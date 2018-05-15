class Solution {
public:
    void dfs(int guy, vector<int>& visited, vector<vector<int>>& M){
        visited[guy] = 1;
        for(int i = 0; i < visited.size(); i++){
            if(M[guy][i] == 1 && !visited[i])
                dfs(i, visited, M);
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        vector<int> visited(n, 0);
        int result = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i, visited, M);
                result ++;
            }
        }
        return result;
    }
};
