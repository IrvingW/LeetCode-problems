class Solution {
public:
    pair<int, int> zeroOne(string str){
        pair<int, int> p (0, 0);
        for(int i = 0; i< str.size(); i++){
            if(str[i] == '0')
                p.first ++;
            else 
                p.second ++;
        }
        return p;
    }
    // 2D 0/1 pakage problem
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp (m+1, vector<int> (n+1, 0));
        for(auto str : strs){
            pair<int, int> p = zeroOne(str);
            int M = p.first;
            int N = p.second;
            for(int i = m; i >= 0; i--){
                for(int j = n; j >= 0; j--){
                    if(i - M >= 0 && j - N >= 0){
                        dp[i][j] = max(dp[i][j], dp[i-M][j-N] + 1);
                    }
                }
            }
        }
        return dp[m][n];
    }
};
