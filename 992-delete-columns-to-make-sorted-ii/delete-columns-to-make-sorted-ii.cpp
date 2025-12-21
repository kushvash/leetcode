class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();
        int n = strs[0].size();
        vector<char> fixed(m - 1, 0);
        int deletions = 0;

        for (int c = 0; c < n; ++c) {
            bool bad = false;
            for (int j = 0; j < m - 1; ++j) {
                if (!fixed[j] && strs[j][c] > strs[j + 1][c]) {
                    bad = true;
                    break;
                }
            }
            if (bad) {
                deletions++;
                continue;
            }

            for (int j = 0; j < m - 1; ++j) {
                if (!fixed[j] && strs[j][c] < strs[j + 1][c]) {
                    fixed[j] = 1;
                }
            }
        }

        return deletions;
    }
};