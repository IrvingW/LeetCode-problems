class Solution {
public:
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    string reverseVowels(string s) {
        int len = s.length();
        if(len == 0)
            return s;
        int left = 0;
        int right = len - 1;
        while(left < right)
        {
            if(isVowel(s[left]) && isVowel(s[right]))
            {
                swap(s[left++], s[right--]);
            }else if(isVowel(s[left])){
                right--;
            }else if(isVowel(s[right])){
                left++;
            }else{
                left++;
                right--;
            }
        }
        return s;
    }
};
