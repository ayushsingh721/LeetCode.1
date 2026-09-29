class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int len = m + n - 1;

        // Valid parentheses string must have even length
        if (len % 2 == 1)
            return false;

        // Maximum possible balance is len
        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(n, vector<bool>(len + 1, false))
        );

        // Starting cell must be '('
        if (grid[0][0] == ')')
            return false;

        dp[0][0][1] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

                for (int balance = 0; balance <= len; balance++) {

                    int prevBalance;

                    if (grid[i][j] == '(')
                        prevBalance = balance - 1;
                    else
                        prevBalance = balance + 1;

                    if (prevBalance < 0 || prevBalance > len)
                        continue;

                    if (i > 0 && dp[i - 1][j][prevBalance])
                        dp[i][j][balance] = true;

                    if (j > 0 && dp[i][j - 1][prevBalance])
                        dp[i][j][balance] = true;
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};