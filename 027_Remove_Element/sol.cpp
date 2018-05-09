class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cur = 0; // position to exchange
        int len = nums.size();
        if(len == 0){
            return 0;
        }
        int result = 0;
        for(int i = 0; i < len; i++){
            if(nums[i] != val){
                nums[cur] = nums[i];
                cur++;
                result++;
            }
        }
        return result;
    }
};
