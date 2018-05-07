/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool compare(Interval &a, Interval& b){
        return a.end < b.end;
    }
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        //sort(intervals.begin(), intervals.end(),
             //[](Interval& a, Interval& b) {return a.end < b.end;});
        if(intervals.size() == 0)   return 0;
        sort(intervals.begin(), intervals.end(), compare);
        int remain = 1;
        int last_end = intervals[0].end;
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i].start >= last_end) {
                remain++;
                last_end = intervals[i].end;
            }
        }
        return intervals.size() - remain;

    }
};
