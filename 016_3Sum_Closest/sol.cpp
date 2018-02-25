class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> gaps;
        for(int k = 0; k < nums.size() - 2; k++){
            int tg = target - nums[k];
            int i = k + 1;
            int j = nums.size() - 1;
            int min_gap = INT_MAX;
            bool pushed = false;
            while(i < j) {
                if (nums[i] + nums[j] == tg) return target;
                int gap = tg - nums[i] - nums[j];
                if(abs(gap) < abs(min_gap))
                    min_gap = gap;

                bool positive = (nums[i] + nums[j] > tg) ? true : false;
                if (positive == false) {
                    while (i < j && nums[i] == nums[i + 1]) i++;
                    i++;
                } else {
                    while (i < j && nums[j] == nums[j - 1]) j--;
                    j--;
                }
            }
            gaps.push_back(min_gap);
        }

        int min_gap = INT_MAX;
        for(int i = 0; i < gaps.size(); i++){
            if(abs(gaps[i]) < abs(min_gap)){
                min_gap = gaps[i];
            }
        }
        return target-min_gap;


    }
};
