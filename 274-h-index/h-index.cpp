class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size(), res=0;

        for (int i = n - 1; i >= 0; i--) {
            int count = n - i;
            if (citations[i] >= count) {
                res = count;
            } else {
                break;
            }
        }

        return res;
    }
};