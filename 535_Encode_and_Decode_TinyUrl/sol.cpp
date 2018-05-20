class Solution {
private: 
    unordered_map<string, string> short2long, long2short;
    string dict;
public:
    Solution(){
        dict = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        srand(time(NULL));
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(long2short.count(longUrl))   
            return "http://tinyurl.com/" + long2short[longUrl];
        // create new map
        string r;
        for(int i = 0; i < 6; i++){
            int random = rand() % 62;
            r.push_back(dict[random]);
        }
        short2long[r] = longUrl;
        long2short[longUrl] = r;
        return "http://tinyurl.com/" + r;
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int index = shortUrl.rfind('/') + 1;
        string s = shortUrl.substr(index);
        return short2long.count(s) ? short2long[s] : shortUrl;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
