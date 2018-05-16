class Solution {
private:
    bool rowUsed[9][10];
    bool colUsed[9][10];
    bool cubeUsed[9][10];
    
public:
    int cubeNumber(int i, int j){
        int r = i / 3;
        int c = j / 3;
        int result = 3 * r + c;
        return result;
    }

    bool backtracking(vector<vector<char>> & board, int row, int col){
        while(row < 9 && board[row][col] != '.'){
            row = col == 8 ? row+1 : row;
            col = col == 8 ? 0 : col + 1;
        }
        if(row == 9)    return true;
        for(int i = 1; i < 10; i++) { // iterate all nine number
            if(rowUsed[row][i] || colUsed[col][i] || cubeUsed[cubeNumber(row, col)][i])
                continue;   // used
            // try to fill it in
            rowUsed[row][i] = colUsed[col][i] = cubeUsed[cubeNumber(row, col)][i] = true;
            board[row][col] = char('0' + i);

            if(backtracking(board, row, col))
                return true;

            board[row][col] = '.';
            rowUsed[row][i] = colUsed[col][i] = cubeUsed[cubeNumber(row, col)][i] = false;
        }
        return false;
    }

    void solveSudoku(vector<vector<char>> & board){
        // prepare metadata
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                int num = board[i][j] - '0';
                if(num >= 0) {
                    rowUsed[i][num] = true;
                    colUsed[j][num] = true;
                    cubeUsed[cubeNumber(i, j)][num] = true;

                }
            }
        }
        // backtracking
        backtracking(board, 0, 0);
    }
};
