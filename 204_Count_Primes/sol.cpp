class Solution {
public:
    int countPrimes(int n) {
        if(n < 3)   return 0;
        vector<int> isPrime(n, true);
        int prime = 2;
        while(prime * prime <= n - 1){
            for(int i = 2; i * prime < n; i++){
                isPrime[i * prime] = false;
            }
            for(int i = prime + 1; i < n; i++){
                if(isPrime[i] == true){
                    prime = i;
                    break;
                }
            }
        }
        int result = 0;
        for(int i = 2; i < n; i++){
            if(isPrime[i])
                result ++;
        }
        return result;
    }
};
