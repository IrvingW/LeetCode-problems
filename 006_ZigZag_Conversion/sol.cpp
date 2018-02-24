class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows >= s.length()){
            return s;
        }
        
        string result = "";
        int length = s.length();
        vector<string> rows(numRows);
        int step = 1;
        int row_index = 0;
        for(int i = 0; i < length; i++){
            rows[row_index] += s[i];
            if(row_index == (numRows-1))
                step = -1;
            if(row_index == 0)
                step = 1;
            row_index += step;
        }
        for(int i = 0; i < numRows; i++){
            result += rows[i];
        }
        return result;
    }
};
