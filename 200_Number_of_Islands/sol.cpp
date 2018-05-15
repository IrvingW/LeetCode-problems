class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n){
        stack<pair<int, int>> s;
        s.push(pair<int, int>(i, j));
        while(!s.empty()){
            pair<int, int> p = s.top();
            s.pop();
            int a = p.first;
            int b = p.second;
            
            if(grid[a][b] == '0')
                continue;
            grid[a][b] = '0';   // visit
            if(a - 1 >= 0 && grid[a-1][b] == '1')
                s.push(pair<int, int> (a-1, b));
            if(a + 1 < m && grid[a+1][b] == '1')
                s.push(pair<int, int> (a+1, b));
            if(b + 1 < n && grid[a][b+1] == '1')
                s.push(pair<int, int> (a, b+1));
            if(b - 1 >= 0 && grid[a][b-1] == '1')
                s.push(pair<int, int> (a, b-1));                
            
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        int result = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    result ++;
                    dfs(grid, i, j, m, n);
                }
            }
        }
        return result;
    }
};
