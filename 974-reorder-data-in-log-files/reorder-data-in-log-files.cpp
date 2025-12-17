class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<string, string>> letterLogs;
        vector<pair<string, string>> intLogs;

        for(string& s: logs) {
            int identifierEnd=0;

            for(int i=0; i<s.size(); i++) {
                if(s[i]==' ') {
                    identifierEnd=i;
                    break;
                }
            }

            string identifier=s.substr(0, identifierEnd);

            string logs = s.substr(identifierEnd+1, s.size()-(identifierEnd+1));

            if(s[identifierEnd+1]>='0' && s[identifierEnd+1]<='9') {
                intLogs.push_back({identifier, logs});
            }else {
                letterLogs.push_back({identifier, logs});
            }
        }

        auto cmp=[](const pair<string, string>& a, const pair<string, string>& b) {
            if(a.second==b.second) {
                return a.first<b.first;
            }

            return a.second<b.second;
        };

        sort(letterLogs.begin(), letterLogs.end(), cmp);

        vector<string> res;

        // letter logs
        for(auto& [iden, str]: letterLogs) {
            res.push_back(iden + ' ' + str);
        }

        for(auto& [iden, str]: intLogs) {
            res.push_back(iden + ' ' + str);
        }

        return res;
    }
};