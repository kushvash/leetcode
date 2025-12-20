class Solution {
public:
    bool isAlphaNum(string s) {
        if(s.empty()) {
            return false;
        }

        for(char c: s) {
            if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9') || (c=='_')) {
                continue;
            }

            return false;
        }

        return true;
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n=code.size();
        map<string, vector<string>> list;
        unordered_set<string> businessList;
        businessList={"electronics", "grocery", "pharmacy", "restaurant"};

        for(int i=0; i<n; i++) {
            if(isActive[i] && isAlphaNum(code[i]) && businessList.find(businessLine[i])!=businessList.end()) {
                list[businessLine[i]].push_back(code[i]);
            }
        }

        vector<string> res;

        for(auto& [business, codes]: list) {
            sort(codes.begin(), codes.end());

            for(string s: codes) {
                res.push_back(s);
            }
        }

        return res;
    }
};