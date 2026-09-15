class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Build palindrome table
        for (int len = 1; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;

                if (s[l] == s[r] &&
                    (len <= 2 || pal[l + 1][r - 1])) {
                    pal[l][r] = true;
                }
            }
        }

        // dp[i] = answer for first i characters
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {

            // Don't select a palindrome ending here
            dp[i] = dp[i - 1];

            // Select s[j ... i-1]
            for (int j = 0; j <= i - k; j++) {

                if (pal[j][i - 1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n];
    }
};