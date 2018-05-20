class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        for(auto c : s){
            if(m.count(c))
                m[c] ++;
            else
                m[c] = 1;
        }
        unordered_map<char, int>::iterator it;
        bool odd = false;
        int result = 0;
        for(it = m.begin(); it != m.end(); it++){
            
            if(it->second % 2){
                odd = true;
                result += (it->second - 1);
            }else{
                result += it->second;
            }
        }
        return odd ? result + 1 : result;
    }
};
