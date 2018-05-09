class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        vector<int> result;
        while(i < m && j < n){
            if(nums1[i] <= nums2[j]){
                result.push_back(nums1[i++]);
            }else{
                result.push_back(nums2[j++]);
            }
            
        }
        if(i == m){
            for(; j < n; j++){
                result.push_back(nums2[j]);
            }
        }
        if(j == n){
            for(; i < m; i++){
                result.push_back(nums1[i]);
            }
        }
        nums1 = result;
    }
};
