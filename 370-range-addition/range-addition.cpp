class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length, 0);

        for(auto& update: updates) {
            int inc=update[2];
            res[update[0]]+=inc;
            if(update[1]+1<length) {
                res[update[1]+1]-=inc;
            }
        }

        for(int i=0; i<length-1; i++) {
            res[i+1]+=res[i];
        }

        return res;
    }
};