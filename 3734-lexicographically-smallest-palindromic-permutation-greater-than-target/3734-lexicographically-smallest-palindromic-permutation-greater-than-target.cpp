class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        // Count characters
        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Check whether a palindrome is possible
        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = char('a' + i);
            }
        }

        if (odd > 1)
            return "";

        // Characters available for the left half
        vector<int> half(26, 0);

        for (int i = 0; i < 26; i++) {
            half[i] = cnt[i] / 2;
        }

        int m = n / 2;

        // Construct complete palindrome from left half
        auto makePalindrome = [&](const string& left) {
            string ans = left;

            if (n % 2)
                ans += mid;

            string rev = left;
            reverse(rev.begin(), rev.end());

            ans += rev;

            return ans;
        };

        /*
         * First check whether target's left half can be formed.
         * If yes, the palindrome having exactly this left half
         * might already be strictly greater than target.
         */
        vector<int> rem = half;
        bool possible = true;

        for (int i = 0; i < m; i++) {
            int x = target[i] - 'a';

            if (rem[x] == 0) {
                possible = false;
                break;
            }

            rem[x]--;
        }

        if (possible) {
            string candidate = makePalindrome(target.substr(0, m));

            if (candidate > target)
                return candidate;
        }

        /*
         * Find the smallest left half greater than target[0 ... m-1].
         *
         * We try every possible position as the first position
         * where our answer becomes greater.
         *
         * We go from right to left because changing a later position
         * gives the smallest possible greater string.
         */
        for (int pos = m - 1; pos >= 0; pos--) {

            rem = half;
            bool prefixPossible = true;

            // Match target's prefix [0 ... pos-1]
            for (int i = 0; i < pos; i++) {
                int x = target[i] - 'a';

                if (rem[x] == 0) {
                    prefixPossible = false;
                    break;
                }

                rem[x]--;
            }

            if (!prefixPossible)
                continue;

            int current = target[pos] - 'a';

            // Put the smallest character greater than target[pos]
            for (int c = current + 1; c < 26; c++) {

                if (rem[c] == 0)
                    continue;

                rem[c]--;

                string left = target.substr(0, pos);
                left += char('a' + c);

                // Fill remaining positions with smallest characters
                for (int x = 0; x < 26; x++) {
                    while (rem[x] > 0) {
                        left += char('a' + x);
                        rem[x]--;
                    }
                }

                string candidate = makePalindrome(left);

                if (candidate > target)
                    return candidate;

                // Restore for next attempt
                rem[c]++;
            }
        }

        return "";
    }
};