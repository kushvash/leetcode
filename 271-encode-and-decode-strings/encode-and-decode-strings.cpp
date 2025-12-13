class Codec {
public:
    vector<string> ans;
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        this->ans=strs;

        return "";
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));