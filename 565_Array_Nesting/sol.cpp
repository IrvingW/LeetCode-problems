class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        // 最后一定是会变成一个环
        int result = 1;
        vector<bool> visited (nums.size(), false);
        for(int i = 0; i < nums.size(); i++){
            if(visited[i])  continue;
            visited[i] = true;
            int len = 1;
            int next = nums[i];
            while(!visited[next]){
                visited[next] = true;
                next = nums[next];
                result = max(result, ++len);
            }
        }
        return result;
    }
};
