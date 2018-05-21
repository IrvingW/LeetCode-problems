class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        int left = 1;
        int right = n;
        while(left < right){
            int cnt = 0;
            int mid = left + (right - left)/2;
            for(auto num : nums){
                if(num <= mid)
                    cnt ++;
            }
            if(cnt <= mid) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};
