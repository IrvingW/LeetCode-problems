class Solution {
public:
    bool check(int i, int j, vector<vector<int>> & matrix){
        int num = matrix[i][j];
        while(i < matrix.size() && j < matrix[0].size()){
            if(matrix[i][j] != num)
                return false;
            i++;
            j++;
        }
        return true;
    }
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0)  return false;
        int n = matrix[0].size();
        if(n == 0)  return false;
        
        pair<int, int> pos (m-1, 0);
        for(int i = m-1; i >= 0; i--){
            if(!check(i, 0, matrix))
                return false;
        }
        for(int j = 1; j < n; j++){
            if(!check(0, j, matrix))
                return false;
        }
        return true;
    }
};
