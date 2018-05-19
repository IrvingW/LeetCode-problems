class Solution {
public:
    string convertToBase7(int num) {
        string result;
        if(num == 0)    return "0";
        bool positive = (num > 0);
        while(num != 0){
            int a = abs(num % 7);
            result = to_string(a) + result;
            num = num / 7;
        }
        if(!positive)
            result = "-" + result;
        return result;
    }
};
