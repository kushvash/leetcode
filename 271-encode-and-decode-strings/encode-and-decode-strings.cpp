class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res="";

        for(string& str: strs) {
            res+=to_string(str.size());
            res+="#";
            res+=str;
        }

        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int start=0;
        vector<string> res;

        while(start<s.size()){
            int end=start;

            while(s[end]!='#'){
                end++;
            }

            int length=stoi(s.substr(start, end-start));

            start=end+1;
            end=start+length;

            res.push_back(s.substr(start, length));

            start=end;
        }

        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));