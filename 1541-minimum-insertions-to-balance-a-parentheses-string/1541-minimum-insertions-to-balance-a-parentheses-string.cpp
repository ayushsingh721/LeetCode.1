
class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int open = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                open++;
            }
            else {
                // If next character is ')', use it as a pair
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;
                }
                else {
                    // Insert one ')' to complete the pair
                    insertions++;
                }

                // Match the closing pair with an opening '('
                if (open > 0) {
                    open--;
                }
                else {
                    // Insert '(' because no opening bracket exists
                    insertions++;
                }
            }
        }

        // Each remaining '(' needs two ')'
        return insertions + 2 * open;
    }
};
