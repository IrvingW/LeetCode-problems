class Solution {
public:
    
    static bool compare(const pair<int, int> a, const pair<int, int> b){
        if(a.first == b.first)
            return a.second < b.second;
        else{
            return a.first > b.first;
        }
    }

    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), compare);
        vector<pair<int, int>> result;
        for(int i = 0; i < people.size(); i++){
            result.insert(result.begin() + people[i].second, people[i]);
        }
        return result;
    }
};
