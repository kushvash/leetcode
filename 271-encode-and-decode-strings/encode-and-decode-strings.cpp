class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        for(string& str: strs) {
            int sz=str.size();

            res+=to_string(sz);
            res+='#';
            res+=str;
        }

        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int i=0;

        while(i<s.size()) {
            int j=i;
            while(s[j]!='#') {
                j++;
            }

            int sz=stoi(s.substr(i, j-i+1));

            i=j+1;

            res.push_back(s.substr(i, sz));

            i+=sz;
        }

        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));