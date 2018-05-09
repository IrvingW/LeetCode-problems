class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() == 0)   return true;
        int index = 0;
        for(int i = 0; i < s.size(); i++){
            char x = s[i];
            int r = t.find(x, index);
            if(r == -1)
                return false;
            index = r + 1;
        }
        return true;
    }
};
