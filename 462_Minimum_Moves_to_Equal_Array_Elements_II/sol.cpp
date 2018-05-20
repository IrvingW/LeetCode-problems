class Solution {
public:
    int partition(vector<int> &nums, int left, int right){
        int pivot = nums[left];
        while(left < right){
            while(left < right && nums[right] >= pivot)
                right--;
            nums[left] = nums[right];            
            while(left < right && nums[left] <= pivot)
                left++;
            nums[right] = nums[left];

        }
        nums[left] = pivot;
        return left;
    }
    int findKSmallest(vector<int> &nums, int k){
        int l = 0;
        int r = nums.size() - 1;
        while(true){
            int p = partition(nums, l, r);
            if(p == k - 1) return nums[p];
            if(p > k -1) r = p - 1;
            else    l = p + 1;
        }
        
    }
    
    int minMoves2(vector<int>& nums) {
        int size = nums.size();
        int mid = 0;
        mid = findKSmallest(nums, (size+1)/ 2);
        int result = 0;
        for(int i = 0; i < size; i++){
            result += abs(nums[i] - mid);
        }
        return result;
        
    }
};
