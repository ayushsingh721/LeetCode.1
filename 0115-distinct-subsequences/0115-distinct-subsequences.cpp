class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));

        // Empty t can be formed in exactly one way
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                // Don't use s[i-1]
                dp[i][j] = dp[i - 1][j];

                // Use s[i-1] if characters match
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] += dp[i - 1][j - 1];

                    // Prevent intermediate overflow
                    if (dp[i][j] > INT_MAX) {
                        dp[i][j] = INT_MAX;
                    }
                }
            }
        }

        return (int)dp[m][n];
    }
};