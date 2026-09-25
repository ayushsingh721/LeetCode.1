class Solution {
public:

    set<string> parse(string& s, int& i) {

        set<string> result;
        set<string> curr = {""};

        while (i < s.size() && s[i] != '}') {

            if (s[i] == ',') {
                // Union:
                // add current expressions to result
                result.insert(curr.begin(), curr.end());

                curr = {""};
                i++;
            }

            else if (s[i] == '{') {

                i++; // skip '{'

                set<string> inside = parse(s, i);

                i++; // skip '}'

                // Concatenate curr × inside
                set<string> temp;

                for (string a : curr) {
                    for (string b : inside) {
                        temp.insert(a + b);
                    }
                }

                curr = temp;
            }

            else {
                // Single lowercase letter
                string ch(1, s[i]);

                set<string> temp;

                for (string a : curr) {
                    temp.insert(a + ch);
                }

                curr = temp;

                i++;
            }
        }

        // Add final part
        result.insert(curr.begin(), curr.end());

        return result;
    }


    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> ans = parse(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};