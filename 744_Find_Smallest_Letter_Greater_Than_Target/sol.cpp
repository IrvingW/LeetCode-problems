class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size();
        while(left < right){
            int m = left + (right - left)/2;
            if(letters[m] <= target)
                left = m + 1;
            else
                right = m;
        }
        if(right == letters.size())
            right = 0;
        return letters[right];
    }
};
