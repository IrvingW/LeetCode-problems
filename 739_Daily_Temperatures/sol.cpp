class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        if(temperatures.size() == 0)    return {};
        stack<int> history;
        vector<int> result (temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++){
            int temp = temperatures[i];
            if(history.empty()){
                history.push(i);
            }else{
                if(temp > temperatures[history.top()]){
                    while(!history.empty() && temp > temperatures[history.top()]){
                        result[history.top()] = i - history.top();
                        history.pop();
                    }
                    history.push(i);
                }else{
                    history.push(i);
                }
            }
        }
        return result;
    }
};
