class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> in(numCourses, 0);
        vector<vector<int>> graph (numCourses, vector<int>(0));
        // made graph
        for(auto pre : prerequisites){
            graph[pre.second].push_back(pre.first);
            in[pre.first] ++ ;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(in[i] == 0)
                q.push(i);
        }
        while(!q.empty()){
            int in_zero = q.front();
            q.pop();
            for(auto out : graph[in_zero]){
                in[out]--;
                if(in[out] == 0)
                    q.push(out);
            }
        }
        for(auto zero : in){
            if(zero != 0)
                return false;
        }
        return true;
        
    }
};
