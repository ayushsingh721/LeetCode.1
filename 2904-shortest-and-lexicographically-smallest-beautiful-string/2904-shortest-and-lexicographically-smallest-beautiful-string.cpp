class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0, Ones = 0;
        int minLen = INT_MAX;
        string ans = "";

        for(int right = 0; right < n; right++){
            if(s[right] == '1'){
                Ones++;
            }
            while(Ones > k){
                if(s[left] == '1'){
                    Ones--;
                }
                left++;
            }

            if(Ones == k){
                int temp = left;
                while (temp <= right && s[temp] == '0'){
                    temp ++;
                }
                int len = right - temp + 1;

                if(len < minLen){
                    minLen = len;
                    ans = s.substr(temp, len);
                }
                else if (len == minLen) {
                    string cur = s.substr(temp, len);
                    if(cur < ans){
                        ans = cur;
                    }
                }
            }
        }
        return ans;
    }
};