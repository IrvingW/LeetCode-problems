class Solution {
public:
    int myAtoi(string str) {
        if(str.empty())
            return 0;
        
        int sign = 1;
        int base = 0;
        int len = str.size();
        int i = 0;  // index
        while(i < len && str[i] == ' ')
            i++;    // skip over blank part
    
        int first_sign = 1;
        while(i < len && (str[i] == '+' || str[i] == '-')){
            if(first_sign == 1){
                if(str[i] == '-'){
                    sign = -1;
                }
                first_sign = 0;
            }
            else
                return 0;
            i++;
        }
    
        // number part
        while(i < len && str[i] >= '0' && str[i] <= '9'){
            if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            int number = str[i] - '0';
            base = base * 10 + number;
            i++;
        }
        return base * sign;
        
    }
};
