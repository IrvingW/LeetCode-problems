class Solution {
public:

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> dict(wordList.begin(), wordList.end());
        if(dict.find(endWord) == dict.end())
            return 0;

        int result = 0;

        queue<string> q;
        q.push(beginWord);
        while(!q.empty()){
            int size = q.size();
            for(int k = 0; k < size; k++){  // pop a layer
                string s = q.front();
                q.pop();
                result ++;

                for(int  i = 0; i < s.size(); i++){
                    char origin = s[i];
                    for(int j = 'a'; j <= 'z'; j++){
                        if(j == origin)
                            continue;
                        else{
                            s[i] = j;
                            // reach destination
                            if(s == endWord){
                                return result;
                            }
                            if(dict.find(s) != dict.end()){ // got this new word
                                q.push(s);
                                dict.erase(s);
                            }
                        }

                    }
                    s[i] = origin;

                }
            }

        }
        return 0;

    }
};
