class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph (numCourses, vector<int> (0));
        vector<int> in (numCourses, 0);
        // make graph
        for(auto pre : prerequisites){
            graph[pre.second].push_back(pre.first);
            in[pre.first] ++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(in[i] == 0)
                q.push(i);
        }
        
        vector<int> result;
        while(!q.empty()){
            int in_zero = q.front();
            q.pop();
            result.push_back(in_zero);
            for(auto out: graph[in_zero]){
                in[out]--;
                if(in[out] == 0)
                    q.push(out);
            }
        }
        if(result.size() < numCourses)
            return {};
        else
            return result;
    }
};
