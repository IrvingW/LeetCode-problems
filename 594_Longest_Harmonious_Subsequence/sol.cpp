class Solution {
public:
    int findLHS(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        map<int, int> m;
        for(auto num : nums){
            if(!m.count(num))
                m[num] = 1;
            else
                m[num]++;
        }
        map<int, int>::iterator pre = m.begin();
        map<int, int>::iterator it;
        int r = 0;
        for(it = next(pre); it != m.end(); it++){
            if(it->first - pre->first == 1)
                r = max(it->second + pre->second, r);
            pre++;
        }
        return r;
    }
};
