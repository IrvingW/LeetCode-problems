class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string result = "";
        while(i >= 0 || j >= 0 || carry == 1){
            if(i >= 0)  carry += (num1[i--] - '0');
            if(j >= 0)  carry += (num2[j--] - '0');
            result = char(carry % 10 + '0') + result;
            carry /= 10;
        }
        return result;
    }
};
