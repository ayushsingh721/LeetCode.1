class Solution {
public:
    unordered_set<string> ans;

    void dfs(string &s, int index, int leftRem, int rightRem, int balance,
             string curr) {

        // Invalid balance
        if (balance < 0) return;

        // End of string
        if (index == s.size()) {
            if (balance == 0 && leftRem == 0 && rightRem == 0) {
                ans.insert(curr);
            }
            return;
        }

        char ch = s[index];

        // Case 1: Remove current character
        if (ch == '(' && leftRem > 0) {
            dfs(s, index + 1, leftRem - 1, rightRem, balance, curr);
        }

        if (ch == ')' && rightRem > 0) {
            dfs(s, index + 1, leftRem, rightRem - 1, balance, curr);
        }

        // Case 2: Keep current character
        if (ch == '(') {
            dfs(s, index + 1, leftRem, rightRem,
                balance + 1, curr + ch);
        }
        else if (ch == ')') {
            dfs(s, index + 1, leftRem, rightRem,
                balance - 1, curr + ch);
        }
        else {
            // Letter
            dfs(s, index + 1, leftRem, rightRem,
                balance, curr + ch);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRem = 0;
        int rightRem = 0;

        // Find minimum removals
        for (char ch : s) {
            if (ch == '(') {
                leftRem++;
            }
            else if (ch == ')') {
                if (leftRem > 0)
                    leftRem--;
                else
                    rightRem++;
            }
        }

        dfs(s, 0, leftRem, rightRem, 0, "");

        return vector<string>(ans.begin(), ans.end());
    }
};