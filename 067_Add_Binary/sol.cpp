class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        while(carry || i >= 0 || j >= 0){
            if(i >= 0 && a[i--] == '1')   carry ++;
            if(j >= 0 && b[j--] == '1')   carry ++;
            result = char('0' + (carry % 2)) + result;
            carry /= 2;
        }
        return result;
    }
};
