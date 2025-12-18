class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length, 0);

        // creating a diff array
        for (auto &u : updates) {
            int left = u[0], right = u[1], inc = u[2];
            res[left] += inc;
            if (right + 1 < length) {
                res[right + 1] -= inc;
            }
        }

        for (int i=0; i<length-1; i++) {
            res[i+1]+=res[i];
        }

        return res;
    }
};