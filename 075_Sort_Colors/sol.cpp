class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = -1;
        int white = 0;
        int blue = nums.size();
        while(white < blue){
            if(nums[white] == 0)
                swap(nums[++red], nums[white++]);
            else if(nums[white] == 2)
                swap(nums[--blue], nums[white]);
            else
                white++;
        }
    }
};
