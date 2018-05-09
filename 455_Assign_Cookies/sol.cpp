class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cnt = 0;
        int child_index = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= g[child_index]){
                child_index ++;
                cnt ++;
            }
            if(cnt == g.size())
                return cnt;
        }
        return cnt;
    }
};
