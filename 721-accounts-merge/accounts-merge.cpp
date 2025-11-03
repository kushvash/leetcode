class Solution {
public:
    unordered_set<string> visited;
    unordered_map<string, vector<string>> adjacent;

    void DFS(vector<string>& mergedAccount, string& firstEmail) {
        visited.insert(firstEmail);
        mergedAccount.push_back(firstEmail);

        for(string& currentEmail: adjacent[firstEmail]) {
            if(visited.find(currentEmail)==visited.end()) {
                DFS(mergedAccount, currentEmail);
            }
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for(vector<string>& account: accounts) {
            string firstEmail=account[1];
            for(int i=2; i<account.size(); i++) {
                adjacent[firstEmail].push_back(account[i]);
                adjacent[account[i]].push_back(firstEmail);
            }
        }

        vector<vector<string>> res;

        for(vector<string>& account: accounts) {
            string name=account[0];
            string firstEmail=account[1];

            for(int i=1; i<account.size(); i++) {
                if(visited.find(account[i])==visited.end()) {
                    vector<string> mergedAccount;
                    mergedAccount.push_back(name);
                    DFS(mergedAccount, firstEmail);
                    sort(mergedAccount.begin()+1, mergedAccount.end());
                    res.push_back(mergedAccount);
                }
            }
        }

        return res;
    }
};