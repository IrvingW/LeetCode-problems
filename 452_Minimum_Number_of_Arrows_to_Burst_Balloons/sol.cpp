class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int size = points.size();
        if(size == 0)   return 0;
        
        sort(points.begin(), points.end(), [](pair<int, int> a, pair<int,int> b)
             {return a.second < b.second;});
        int last_end = points[0].second;
        int result = 1;
        for(int i = 1; i < size; i++){
            if(points[i].first > last_end){
                result ++;
                last_end = points[i].second;
            }
        }
        return result;
    }
};
