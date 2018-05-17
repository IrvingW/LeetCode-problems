class Solution {
public:
    bool isValid(vector<int> & pos, int row, int col){
        for(int i = 0; i < row; i++){   // iterate before rows
            if(col == pos[i] || row - i == abs(col - pos[i]))
                return false;
        }
        return true;
    }
    
    void backtracking(vector<vector<int>> & result, int row, vector<int> & pos){
        int n = pos.size();
        if(row == n){
            result.push_back(pos);
            return;
        }
        for(int i = 0; i < n; i++){ // search a proper col
            if(isValid(pos, row, i)){
                pos[row] = i;
                backtracking(result, row + 1, pos);
                pos[row] = -1;
            }
        }
    }
    
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<int>> result;
        vector<int> pos (n, -1);
        backtracking(result, 0, pos);
        
        // deal with result
        vector<vector<string>> r;
        for(int i = 0; i < result.size(); i++){
            vector<string> mat (n, string(n, '.'));
            pos = result[i];
            for(int j = 0; j < n; j++){
                mat[j][pos[j]] = 'Q';
            }
            r.push_back(mat);
        }
        return r;
    }
};
