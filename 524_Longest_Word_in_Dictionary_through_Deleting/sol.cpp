class Solution {
public:
    static bool compare(string a, string b){
        if(a.size() == b.size())
            return a < b;
        else
            return a.size() > b.size();
    }

    
    bool match(string s, string target){
        if(s.size() < target.size())    return false;
        int i = 0;
        int j = 0;
        while(j < target.size()){
            if(i == s.size())   return false;
            if(s[i] == target[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return true;
    }
    
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), compare);
        for(int i = 0; i < d.size(); i++){
            string target = d[i];
            if(match(s, target))
                return target;
        }
        return "";
    }
    
};
