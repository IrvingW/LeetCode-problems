class Solution {
public:
    int numDecodings(string s) {
        // dp[n] = sum(dp[n-1] + dp[n-2])   // if str(n-2, n) <= 26
        int n = s.size();
        if(s[0] == '0')
            return 0;
        if(n == 1)
            return 1;
        int dp[n+1];
        dp[1] = 1;
        int a =  atoi(s.substr(0, 2).c_str());
        if(a > 26 && a%10==0)   return 0;
        dp[2] = (a <= 26 && a != 10 && a != 20) ? 2 : 1;
        for(int i = 3; i <= n; i++){
            if(s[i-1] != '0')
                dp[i] = dp[i-1];
            else
                dp[i] = 0;
            
            if(atoi(s.substr(i-2, 2).c_str()) <= 26 && atoi(s.substr(i-2, 2).c_str()) >= 10)
                dp[i] += dp[i - 2];
        }
        return dp[n];
    }
};
