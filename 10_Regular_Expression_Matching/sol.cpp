class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty())
            return s.empty();
        if(p.length() == 1){
            return (s.length() == 1 && (s[0] == p[0] || p[0] == '.'));
        }
        if(p[1] != '*'){
            if(s.empty())
                return false;
            return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1)) ;
        }else{
            while(!s.empty() && (s[0] == p[0] || p[0] == '.')){
                if(isMatch(s, p.substr(2))) return true;    // * match zero char
                s = s.substr(1);    // add one more char
            }
            return isMatch(s, p.substr(2)); // get over * part
        }
    }
    
};  
