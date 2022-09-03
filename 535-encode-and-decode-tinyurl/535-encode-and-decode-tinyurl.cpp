class Solution {
public:
    
    // Encodes a URL to a shortened URL.
    map<string , string> mp;
    int count=0;
    string encode(string longUrl) {
        string res = "http://tinyurl.com/" + to_string(count);
        mp[to_string(count)] = longUrl;
        return res;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int i = 0 ;
         string s;
        for( i=0;i<shortUrl.length() ;i++){
            if(shortUrl[i] >= '0')
                 s = shortUrl.substr(i, shortUrl.length());
        }
       
        return mp[s];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));