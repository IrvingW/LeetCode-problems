class Solution {
public:
    void dfs(int i, int j, vector<vector<char>> &board){
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != 'O')
            return;
        board[i][j] = 'V';
        dfs(i-1, j, board);
        dfs(i+1, j, board);
        dfs(i, j-1, board);
        dfs(i, j+1, board);
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m == 0)  return;
        int n = board[0].size();
       
        
        for(int i = 0; i < n; i++){
            if(board[0][i] == 'O')
                dfs(0, i, board);
        }
        for(int i = 0; i < n; i++){
            if(board[m-1][i] == 'O')
                dfs(m-1, i, board);
        }
        for(int j = 1; j < m-1; j++){
            if(board[j][0] == 'O')
                dfs(j, 0, board);
        }
        for(int j = 1; j < m-1; j++){
            if(board[j][n-1] == 'O')
                dfs(j, n-1, board);
        }
        
        // replace O with X
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'V')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};
