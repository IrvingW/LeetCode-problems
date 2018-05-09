class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while(left < right){
            int m = left + (right - left)/2;
            if(nums[left] <= nums[m] && nums[m] <= nums[right])
                return nums[left];
            if(nums[left] > nums[m])
                right = m;
            if(nums[right] < nums[m])
                left = m + 1;
        }
        return nums[left];
    }
};
