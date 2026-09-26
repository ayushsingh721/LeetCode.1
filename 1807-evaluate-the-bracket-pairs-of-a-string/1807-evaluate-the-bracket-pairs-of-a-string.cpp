class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        unordered_map<string, string> mp;

        // Store knowledge in hashmap
        for (auto &x : knowledge) {
            mp[x[0]] = x[1];
        }

        string ans = "";

        // Traverse string
        for (int i = 0; i < s.length(); i++) {

            if (s[i] != '(') {
                ans += s[i];
            }
            else {
                int j = i + 1;

                // Find closing bracket
                while (s[j] != ')') {
                    j++;
                }

                // Extract key
                string key = s.substr(i + 1, j - i - 1);

                // Check if key exists
                if (mp.find(key) != mp.end()) {
                    ans += mp[key];
                }
                else {
                    ans += '?';
                }

                // Jump to character after ')'
                i = j;
            }
        }

        return ans;
    }
};