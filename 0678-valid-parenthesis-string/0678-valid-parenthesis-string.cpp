class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        for (char ch : s) {

            if (ch == '(') {
                low++;
                high++;
            }
            else if (ch == ')') {
                low--;
                high--;
            }
            else { // '*'
                low--;   // '*' as ')'
                high++;  // '*' as '('
            }

            // We can never have fewer than 0 open brackets
            low = max(0, low);

            // Even the maximum possibility is negative
            if (high < 0) {
                return false;
            }
        }

        // If 0 is possible, string can be valid
        return low == 0;
    }
};