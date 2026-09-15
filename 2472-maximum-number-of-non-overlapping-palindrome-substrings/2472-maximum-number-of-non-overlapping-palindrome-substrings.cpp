class Solution {
public:
    bool isPal(string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i + k <= n; ) {

            if (isPal(s, i, i + k - 1)) {
                ans++;
                i += k;
            }
            else if (i + k < n && isPal(s, i, i + k)) {
                ans++;
                i += k + 1;
            }
            else {
                i++;
            }
        }

        return ans;
    }
};