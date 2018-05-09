class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        int size = flowerbed.size();
        if(size == 0)   return false;
        for(int i = 0; i < size; i++){
            if(flowerbed[i] == 1)
                continue;
            int pre = (i==0)? 0 : i - 1;
            int next = (i == size-1)? i : i+1;
            if(flowerbed[pre] == 0 && flowerbed[next] == 0){
                cnt++;
                flowerbed[i] = 1;
            }            
        }
        return (cnt >= n);
    }
};
