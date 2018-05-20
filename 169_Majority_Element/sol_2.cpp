class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int majority = 0;
        for(auto num : nums){
            majority = (cnt == 0) ? num : majority;
            if(num == majority) cnt++;
            else cnt--;
        }
        return majority;
    }
};
