class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.size() == 0)   return 0;
        sort(pairs.begin(), pairs.end(), [](vector<int> & a, vector<int> & b){
            return a[1] < b[1];
        });
        int last_end = pairs[0][1];
        int result = 1;
        for(int i = 1; i < pairs.size(); i++){
            if(pairs[i][0] > last_end){
                last_end = pairs[i][1];
                result ++;
            }
        }
        return result;
    }
};
