class Solution {
public:
    int r(vector<int>& nums){
        int size = nums.size();
        if(size == 0)   return 0;
        if(size == 1)   return nums[0];
        if(size == 2)   return max(nums[0], nums[1]);
        int pp = nums[0];
        int p = max(nums[1], nums[0]);
        int index = 2;
        while(index < size){
            int next = max(pp + nums[index], p);
            pp = p;
            p = next;
            index ++;
        }
        return p;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 0)    return 0;
        if(nums.size() == 1)    return nums[0];
        vector<int> nohead;
        nohead.assign(nums.begin()+1, nums.end());
        vector<int> notail;
        notail.assign(nums.begin(), nums.end()-1);
        return max(r(nohead), r(notail));
    }
};
