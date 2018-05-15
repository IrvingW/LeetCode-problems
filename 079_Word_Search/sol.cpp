class Solution {
private:
    int m, n;
    vector<vector<int>> visited;
public:
    bool match(vector<vector<char>>& board, string s, int i, int j){
        if(s.size() == 0)   return true;
        
        visited[i][j] = 1;
        char c = s[0];
        bool result = false;
        if(i-1 >= 0 && c == board[i-1][j] && visited[i-1][j] == 0){
            bool m = match(board, s.substr(1), i-1, j);
            if(m)   return true;
        }
        if(i+1 < m && c == board[i+1][j] && visited[i+1][j] == 0){
            bool m = match(board, s.substr(1), i+1, j);
            if(m)   return true;
        }
        if(j-1 >= 0 && c == board[i][j-1] && visited[i][j-1] == 0){
            bool m = match(board, s.substr(1), i, j-1);
            if(m)   return true;
        }
        if(j+1 < n && c == board[i][j+1] && visited[i][j+1] == 0){
            bool m = match(board, s.substr(1), i, j+1);
            if(m)   return true;
        }
        
        visited[i][j] = 0;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size() == 0)    return true;
        char c = word[0];
        m = board.size();
        if(m == 0)  return false;
        n = board[0].size();
        vector<int> row (n, 0);
        vector<vector<int>> v (m, row);
        visited = v;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == c){
                    if(match(board, word.substr(1), i, j)) 
                        return true;
                }
            }
        }
        return false;
    }
};
