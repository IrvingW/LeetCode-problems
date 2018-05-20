class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s_map;
        unordered_map<char, char> t_map;
        for(int i = 0; i < s.size(); i++){
            if(s_map.count(s[i])){
                if(s_map[s[i]] != t[i])
                    return false;
            }else{
                if(s_map.count(s[i]) || t_map.count(t[i])) 
                    return false;
                
                s_map[s[i]] = t[i];
                t_map[t[i]] = s[i];
            }
        }
        return true;
    }
};
