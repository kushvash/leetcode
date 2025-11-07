class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;

        for(string& s: strs) {
            res+=to_string(s.length())+'#'+s;
        }

        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int i=0;

        while(i<s.length()) {
            int e=i;

            while(s[e]!='#') {
                e++;
            }

            int len=stoi(s.substr(i, e-i));

            i=e+1;

            res.push_back(s.substr(i, len));

            i+=len;
        }

        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));