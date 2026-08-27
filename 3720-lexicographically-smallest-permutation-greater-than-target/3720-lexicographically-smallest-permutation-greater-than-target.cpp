class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        // Try every possible position as the first
        // position where answer differs from target.
        for (int i = n - 1; i >= 0; i--) {

            vector<int> freq(26, 0);

            // Count all characters of s
            for (char c : s) {
                freq[c - 'a']++;
            }

            // Use target[0 ... i-1]
            bool possible = true;

            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';

                if (freq[x] == 0) {
                    possible = false;
                    break;
                }

                freq[x]--;
            }

            if (!possible)
                continue;

            // At position i, we need the smallest
            // character strictly greater than target[i].
            int x = target[i] - 'a';

            for (int c = x + 1; c < 26; c++) {

                if (freq[c] > 0) {

                    string ans = target.substr(0, i);
                    ans += char('a' + c);

                    freq[c]--;

                    // Remaining characters in sorted order
                    for (int j = 0; j < 26; j++) {
                        while (freq[j] > 0) {
                            ans += char('a' + j);
                            freq[j]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};