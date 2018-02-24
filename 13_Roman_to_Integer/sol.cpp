class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        map<char, int> value_map = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int len = s.length();
        for(int i = 0; i < len-1; i++){
            char cur_char = s[i];
            int cur = value_map[cur_char];
            char next_char = s[i+1];
            if(cur >= value_map[next_char]){
                result += cur;
            }else{
                result -= cur;
            }
        }
        result += value_map[s[len-1]];
        return result;
    }
};
