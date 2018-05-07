class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> result;
        if(S.size() == 0)   return result;

        int last_index[26];
        for(int i = 0; i < S.size(); i++){
            last_index[S[i] - 'a'] = i;
        }
        int begin = 0;
        int left = 0;
        int right = last_index[S[0] - 'a'];
        while(right != S.size() - 1){
            if(left == right){
                result.push_back(right - begin + 1);
                left = right + 1;
                begin = left;
                right = last_index[S[left] - 'a'];
            }else{
                char x = S[left];
                right = max(last_index[x-'a'], right);
                left ++;
            }

        }
        result.push_back(right - begin + 1);
        return result;
    }
};
