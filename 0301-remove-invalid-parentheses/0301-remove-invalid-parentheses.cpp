class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> current_level;
        unordered_set<string> next_level;
        vector<string> result;
        
        current_level.insert(s);
        
        while (true) {
            for (const string& str : current_level) {
                if (isValid(str)) {
                    result.push_back(str);
                }
            }
            
            if (!result.empty()) {
                return result;
            }
            
            for (const string& str : current_level) {
                for (int i = 0; i < str.length(); ++i) {
                    if (str[i] != '(' && str[i] != ')') continue;
                    string next_str = str.substr(0, i) + str.substr(i + 1);
                    next_level.insert(next_str);
                }
            }
            
            current_level = move(next_level);
            next_level.clear();
        }
    }

private:
    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') {
                count++;
            } else if (c == ')') {
                count--;
                if (count < 0) return false;
            }
        }
        return count == 0;
    }
};