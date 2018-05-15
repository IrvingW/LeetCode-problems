class Solution {
public:
    int str2int(string str){
        if(str.size() == 0) return -1;
        int result = 0;
        for(int i = 0; i < str.size(); i++){
            result *= 10;
            result += str[i] - '0';
        }
        return result;
    }
    
    void restore(vector<string> & result, int level, string s, string pre){
        if(level == 1){
            if(s[0] == '0' && s.size() > 1) return; // important
            if(0 <= str2int(s) && str2int(s) <= 255)
                result.push_back(pre+s);
            else
                return;
        }
        int index = 1;
        int size = s.size();
        while(true){
            if(index >= size)
                return;
            string prefix = s.substr(0, index);
            int p = str2int(prefix);
            if(0 <= p && p <= 255){
                restore(result, level-1, s.substr(index), pre+prefix+".");
                if(p == 0)  break;
            }
            else
                break;
            index ++;
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        restore(result, 4, s, "");
        return result;
    }
};
