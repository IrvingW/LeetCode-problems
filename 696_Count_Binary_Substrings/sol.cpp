class Solution {
public:
    int countBinarySubstrings(string s) {
        int result = 0;
        int digits[2];
        digits[0] = 0;
        digits[1] = 0;
        int last = 0;
        for(int i = 0; i < s.size(); i++){
            int cur = s[i] - '0';
            if(cur != last){
                digits[cur] = 0;
                last = cur;
            }
            digits[cur] ++;
            
            if(digits[cur] <= digits[(cur + 1) % 2])
                result ++;
            
        }
        return result;
    }
};
