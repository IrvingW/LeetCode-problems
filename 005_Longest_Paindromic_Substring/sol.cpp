// Dynamic Programming
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        bool p[n][n] = {false};
        int max_len = 1;
        int begin = 0;
        
        // initialize p[i][i]
        for(int i = 0; i < n; i++){
            p[i][i] = true;
        }
        
        for(int i = 0; i < n-1; i++){
            if(s[i] == s[i+1]){
                begin = i;
                max_len = 2;
                p[i][i+1] = true;
            }
        }
        
        for(int len = 3; len <= n; len++){
            for(int i = 0; i < n-len+1; i++){
                int j = i + len - 1;
                if(p[i+1][j-1] == true && s[i]== s[j]){
                    begin = i;
                    max_len = len;
                    p[i][j] = true;
                }
            }
        }
        string result = s.substr(begin, max_len);
        return result;
    }
};
