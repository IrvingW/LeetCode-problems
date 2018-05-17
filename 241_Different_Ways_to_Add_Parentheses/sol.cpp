class Solution {
public:
    vector<int> allRes(vector<int> & left, vector<int> & right, char op){
        vector<int> result;
        for(int i = 0; i < left.size(); i++){
            for(int j = 0; j < right.size(); j++){
                if(op == '+')
                    result.push_back(left[i] + right[j]);
                else if(op == '-')
                    result.push_back(left[i] - right[j]);
                else 
                    result.push_back(left[i] * right[j]);
            }
        }
        return result;
    }
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        if(input.size() == 0)   return res;
        
        for(int i = 0; i < input.size(); i++){
            if(input[i] == '+' || input[i] == '-' || input[i] == '*'){
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right= diffWaysToCompute(input.substr(i+1));
                vector<int> allR = allRes(left, right, input[i]);
                res.insert(res.end(), allR.begin(), allR.end());
            }
        }
        if(res.empty())
            res.push_back(atoi(input.c_str()));
        return res;
    }
};
