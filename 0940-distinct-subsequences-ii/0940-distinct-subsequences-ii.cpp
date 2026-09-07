class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1000000007;

        // dp = total distinct subsequences including empty subsequence
        long long dp = 1;

        // last[c] = dp value BEFORE the previous occurrence of c
        vector<long long> last(26, 0);

        for (char c : s) {
            int x = c - 'a';

            long long newDp = (2 * dp - last[x] + MOD) % MOD;

            // Save the old dp before updating it
            last[x] = dp;

            dp = newDp;
        }

        // Remove empty subsequence
        return (dp - 1 + MOD) % MOD;
    }
};