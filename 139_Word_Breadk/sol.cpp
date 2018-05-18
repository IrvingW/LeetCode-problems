class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp (n+1, false);
        dp[0] = true;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < wordDict.size(); j++){
                string word = wordDict[j];
                int len = word.size();
                if(i - len >= 0 && s.substr(i - len, len) == word){
                    dp[i] = dp[i - len] || dp[i];
                }
            }
        }
        return dp[n];
    }
};
