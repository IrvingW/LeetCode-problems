class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if(size == 0)
            return "";
        int min_len = INT_MAX;
        string result = "";
        for(int i = 0; i < size; i++){
            if(strs[i].length() < min_len){
                min_len = strs[i].length();
            }
        }
        
        int i = 0;
        for(; i < min_len; i++){
            char cur_char = strs[0][i];
            for(int j = 1; j < size; j++){
                if(cur_char != strs[j][i]){
                    return result;
                }
            }
            result += cur_char;
        }
        
        return result;
    }
};
