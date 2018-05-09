class Solution {
public:
    int dfs(int i, int j, vector<vector<int>> & grid, int m, int n){
        int result = 0;
        stack<pair<int, int>> s;
        s.push(pair<int, int>(i, j));
        while(!s.empty()){
            pair<int,int> p = s.top();
            s.pop();
            int i = p.first;
            int j = p.second;
            if(grid[i][j] == 0) continue;   // has already been pushed into stack once
            grid[i][j] = 0;
            result ++;
            if(i+1 < m && grid[i+1][j] == 1)
                s.push(pair<int, int>(i+1, j));
            if(i-1 >= 0 && grid[i-1][j] == 1)
                s.push(pair<int, int>(i-1, j));
            if(j+1 < n && grid[i][j+1] == 1)
                s.push(pair<int, int>(i, j+1));
            if(j-1 >= 0 && grid[i][j-1] == 1)
                s.push(pair<int, int>(i, j-1));
        }
        return result;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result = 0;
        int m = grid.size();
        if(m == 0)  return 0;
        int n = grid[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0)
                    continue;
                else
                    result = max(result, dfs(i, j, grid, m, n));
            }
        }
        return result;
    }
};
