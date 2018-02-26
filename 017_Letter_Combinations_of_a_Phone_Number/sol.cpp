class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.empty()) return result;
        string dict[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        dfs(result, dict, digits, "");
        return result;
    }
    
    void dfs(vector<string>& result, string dict[], string digits, string prefix){
        string str = dict[digits[0] - '2'];
        for(int i = 0; i < str.length(); i++){
            if(digits.length() > 1)
                dfs(result, dict, digits.substr(1), prefix+str[i]);
            else 
                result.push_back(prefix+str[i]);
        }
    }
};
