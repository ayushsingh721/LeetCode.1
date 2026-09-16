class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long MOD = 1e9 + 7;

        vector<long long> dp(k + 1, 0);
        vector<long long> open(k + 1, 0);

        dp[0] = 1;

        for (int i = 1; i < n; i++) {

            for (int j = k; j >= 1; j--) {
                // Start a new segment at point i-1
                open[j] = (open[j] + dp[j - 1]) % MOD;

                // End the current segment at point i
                dp[j] = (dp[j] + open[j]) % MOD;
            }
        }

        return dp[k];
    }
};