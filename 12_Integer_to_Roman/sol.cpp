class Solution {
public:
    string intToRoman(int num) {
        int num_array[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string str_array[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};  
        int i = 0;
        string result = "";
        while(num != 0){
            if(num >= num_array[i]){
                num -= num_array[i];
                result += str_array[i];
            }
            else
                i++;
        }
        return result;
    }
};
