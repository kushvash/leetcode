class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        for(string str: strs) {
            int n=str.size();

            res+=to_string(n) + '#' + str;
        }

        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int left=0, n=s.size();

        while(left<n) {
            int right=left;
            while(s[right]!='#') {
                right++;
            }

            int size=stoi(s.substr(left, right-left));

            left=right+1;

            string toAdd=s.substr(left, size);

            res.push_back(toAdd);

            left+=size;
        }

        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));