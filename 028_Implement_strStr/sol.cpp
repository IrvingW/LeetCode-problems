class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        int m = haystack.size(), n = needle.size();
        if(m < n)
            return -1;
        // do not really need to iterate the whole string
        // iterate to the rest length equal to needle.size()
        for(int i = 0; i < m - n + 1; i ++){
            string sub_str = haystack.substr(i, n);
            if(sub_str == needle)
                return i;
        }
        
        return -1;
    }
};
