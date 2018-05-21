class Solution {
private:
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {    
        int m = matrix.size();
        if(m == 0)  return false;
        int n = matrix[0].size();
        if(n == 0)  return false;
        
        pair<int, int> cur (m-1, 0);    // special start point , can be top right also
        while(true){
            if(cur.first < 0 || cur.second >= n)
                return false;
            int num = matrix[cur.first][cur.second];
            if(target == num)
                return true;
            if(target > num){
                cur.second ++;
            }else{
                cur.first --;
            }
        }
    }
};
