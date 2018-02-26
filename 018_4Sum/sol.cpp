class Solution {
public:
    vector<vector<int>> fourSum(vector<int> & nums, int target){
        set<vector<int>> result;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for(int i = 0; i < size - 3; i++){       
            for(int k = i+1; k < size - 2; k++){
                int left = k + 1;
                int right = size - 1;
                while(left < right){
                    int sum = nums[left] + nums[right] + nums[i] + nums[k];
                    if(sum == target){
                        vector<int> four;
                        four.push_back(nums[i]);
                        four.push_back(nums[k]);
                        four.push_back(nums[left]);
                        four.push_back(nums[right]);
                        result.insert(four);
                        left++; right--;
                    }else{
                        if(sum > target){
                            while(left < right && nums[right] == nums[right-1]) 
                                right--;
                            right--;
                        }else{
                            while(left < right && nums[left] == nums[left+1]) 
                                left++;
                            left++;
                        }
                    }
                }

            }
        }
        return vector<vector<int>> (result.begin(), result.end());
    }
};
