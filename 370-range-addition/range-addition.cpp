class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length, 0);

        for(auto& update: updates) {
            int inc=update[2];
            int start=update[0];
            int end=update[1];

            res[start]+=inc;

            if(end+1<length) {
                res[end+1]-=inc;
            }
        }

        for(int i=1; i<length; i++) {
            res[i]+=res[i-1];
        }

        return res;
    }
};