class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length, 0);

        for(auto& update: updates) {
            for(int i=update[0]; i<=update[1]; i++) {
                res[i]+=update[2];
            }
        }

        return res;
    }
};