class Solution {
public:
    string toHex(int num) {
        string result = "";
        if(num == 0)    return "0";
        for(int i = 0; i < 8 && num != 0; i++){
            int temp = 0xf & num;
            char c;
            if(temp >= 10)
                result = char('a' + (temp - 10)) + result;
            else
                result = to_string(temp) + result;
            num = num >> 4;
        }
        return result;
    }
};
