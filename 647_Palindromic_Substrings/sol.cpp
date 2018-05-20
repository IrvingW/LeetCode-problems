class Solution {
public:
    void expand(string & s, int i, int j, int & result){
        while(i >= 0 && j < s.size() && s[i] == s[j]){
            i--;
            j++;
            result ++;
        }
    }
    int countSubstrings(string s) {
        int result = 0;
        for(int i = 0; i < s.size(); i++){
            expand(s, i, i, result);    // take s[i] as the middle element
            expand(s, i, i+1, result);  // even length
        }
        return result;
    }
};
