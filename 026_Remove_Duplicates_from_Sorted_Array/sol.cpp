class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return 0;
        if(len == 1)
            return 1;
        int last = nums[0];
        int cur = 1;    // cur exchange position
        int result = 1;
        for(int i = 1; i < len; i++){
            if(nums[i] == last){
                continue;
            }else{
                result ++;
                last = nums[i];
                if(cur != i){   // exchange
                    nums[cur] = nums[i];
                }
                cur++;
            }
        }
        return result;
    }
};
