class Solution {
public:
    int maxArea(vector<int>& height) {
        int j = height.size() - 1;
        int i = 0;
        int result = 0;
        while(i < j){
            int volumn = min(height[i], height[j]) * (j-i);
            result = volumn > result ? volumn : result;
            if(height[i] < height[j]){
                i++;
            }else
                j--;
        }
        return result;
    }
};
