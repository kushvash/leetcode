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
        int n=s.size(), i=0;
        vector<string> res;

        while(i<n){
            int temp=i;

            while(s[temp]!='#') {
                temp++;
            }

            int len=stoi(s.substr(i, temp-i));

            i=temp+1;
            temp=i+len;

            res.push_back(s.substr(i, len));

            i=temp;
        }

        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));