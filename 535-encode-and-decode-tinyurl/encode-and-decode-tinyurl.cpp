class Solution {
public:
    unordered_map<string, string> longToShort;
    unordered_map<string, string> shortToLong;
    int id = 0;
    const string baseURL = "http://tinyurl.com/";

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(longToShort.find(longUrl)!=longToShort.end()){
            return longToShort[longUrl];
        }

        string shortUrl = baseURL + to_string(id);
        longToShort[longUrl] = shortUrl;
        shortToLong[shortUrl] = longUrl;
        id++;

        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if(shortToLong.count(shortUrl)) {
            return shortToLong[shortUrl];
        }

        return "";
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));