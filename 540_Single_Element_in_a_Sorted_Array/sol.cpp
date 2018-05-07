class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size();
        while(left < right){
            int m = left + (right - left)/2;
            if(m % 2 != 0){
                if(nums[m] == nums[m - 1])
                    left = m + 1;
                else if(nums[m] == nums[m + 1])
                    right = m;
                else
                    return nums[m];
            }else{
                if(nums[m] == nums[m - 1])
                    right = m;
                else if(nums[m] == nums[m + 1])
                    left = m + 1;
                else
                    return nums[m];
            }
        }
        return nums[right];
    }
};
