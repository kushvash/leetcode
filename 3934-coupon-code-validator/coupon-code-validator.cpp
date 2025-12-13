class Solution {
public:
    bool validCode(string s) {
        string res;

        for(char& c: s) {
            if(!isalnum(c) && c!='_') {
                return false;
            }
        }

        return true;
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n=code.size();
        vector<string> res;

        unordered_map<string, vector<string>> mp;

        for(int i=0; i<n; i++) {
            if(!isActive[i] || code[i]=="") {
                continue;
            }

            string business=businessLine[i];
            string couponCode=code[i];

            if(validCode(couponCode)) {
                mp[business].push_back(couponCode);
            }
        }

        vector<string> order = {"electronics", "grocery", "pharmacy", "restaurant"};

        for(string& business: order) {
            sort(mp[business].begin(), mp[business].end());

            for(string& c: mp[business]) {
                res.push_back(c);
            }
        }

        return res;
    }
};