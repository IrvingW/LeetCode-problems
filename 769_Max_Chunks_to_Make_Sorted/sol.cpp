class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        if(n == 0)  return 0;
        if(n == 1)  return 1;
        int begin = 0;
        int end = 0;
        int result = 0;
        while(begin <= n-1){
            end = max(end, arr[begin]);
            if(begin == end){
                result ++;
                begin++;
                continue;
            }
            begin++;
        }
        return result;
    }
};
