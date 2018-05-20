class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> before (n);
        vector<int> after (n);
        int mul = nums[0];
        before[0] = 1;
        for(int i = 1; i < n; i++){
            before[i] = mul;
            mul *= nums[i];
        }
        after[n-1] = 1;
        mul = nums[n-1];
        for(int i = n - 2; i >= 0; i--){
            after[i] = mul;
            mul *= nums[i];
        }
        vector<int> result(n);
        for(int i = 0; i < n; i++){
            result[i] = before[i] * after[i];
        }
        return result;
                        
    }
};
