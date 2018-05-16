class Solution {
public:
    bool palindrome(string str){
        int left = 0;
        int right = str.size() - 1;
        while(left < right){
            if(str[left++] == str[right--])
                continue;
            else
                return false;
        }
        return true;
    }
    void cut(string str, vector<vector<string>> & result, vector<string> prefix, int index){
        if(index == str.size()){
            result.push_back(prefix);
            return;
        }
        for(int i = index; i < str.size(); i++){
            string test = str.substr(index, i - index + 1);
            if(palindrome(test)){
                prefix.push_back(test);
                cut(str, result, prefix, i+1);
                prefix.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> prefix;
        cut(s, result, prefix, 0);
        return result;
    }
};
