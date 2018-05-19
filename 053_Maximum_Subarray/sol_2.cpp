class Solution {
public:
    int divide(int left, int right, vector<int>&nums){
        if(left > right)    return INT_MIN;
        if(left == right)   return nums[left];
        int mid = left + (right - left)/2;
        int lmax = divide(left, mid - 1, nums);
        int rmax = divide(mid + 1, right, nums);
        int mmax = nums[mid];
        int temp = mmax;
        for(int i = mid - 1; i >= left; i--){
            temp += nums[i];
            mmax = max(mmax, temp);
        }
        temp = mmax;
        for(int i = mid + 1; i <= right; i++){
            temp += nums[i];
            mmax = max(mmax, temp);
        }
        return max(mmax, max(lmax, rmax));
    }
    int maxSubArray(vector<int>& nums) {
        return divide(0, nums.size() - 1, nums);
    }
    
};
