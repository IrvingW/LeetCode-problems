class Solution {
public:
    int binarySearch(vector<int> &nums, int target){
        int left = 0;
        int right = nums.size();
        while(left < right){
            int m = left + (right - left) / 2;
            if(nums[m] < target)
                left = m + 1;
            else
                right = m;
        }
        return left;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0)    return {-1, -1};
        vector<int> result;
        int p = binarySearch(nums, target);
        result.push_back(p);
        if(result[0] == -1)
            result.push_back(-1);
        else{
            if(p == nums.size() || nums[p] != target){   // important
                result[0] = -1;
                result.push_back(-1);
                return result;
            }
            for(int i = p + 1; i < nums.size(); i++){
                if(nums[i] != target){
                    result.push_back(i - 1);
                    return result;
                }
            }
            result.push_back(nums.size()-1);
        }
        return result;
        
    }
};
