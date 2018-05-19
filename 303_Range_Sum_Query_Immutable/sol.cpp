class NumArray {
private:
    vector<int> sums;
public:
    NumArray(vector<int> nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            sums.push_back(sum);
        }
    }
    
    int sumRange(int i, int j) {
        int left = (i == 0)? 0 : sums[i-1];
        int right = sums[j];
        return right - left;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
