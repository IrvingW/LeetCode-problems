class Solution {
private:
    int mm, nn;
    int rr, cc;
public:
    pair<int, int> translate(pair<int, int> p){
        int r = p.first;
        int c = p.second;
        int index = r * cc + c + 1;
        pair<int, int> pp;
        pp.first = (index - 1) / nn ;
        pp.second = (index - 1) % nn;
        return pp;
    }
    
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size();
        if(m == 0)  return nums;
        int n = nums[0].size();
        if(m * n != r * c)  return nums;
        
        mm = m;
        nn = n;
        rr = r;
        cc = c;
        vector<vector<int>> result (r, vector<int>(c, 0));
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                pair<int, int> p = translate(pair<int, int> (i, j));
                result[i][j] = nums[p.first][p.second];
            }
        }
        return result;
    }
};
