class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
       unordered_map<string,int> freq;

        for (auto& day : responses) {
            unordered_set<string> seen;
            for (auto& r : day) {
                seen.insert(r);
            }
            for (auto& r : seen) {
                freq[r]++;
            }
        }

        string best;
        int bestCnt = -1;

        for (auto& [resp, cnt] : freq) {
            if (cnt > bestCnt || (cnt == bestCnt && resp < best)) {
                bestCnt = cnt;
                best = resp;
            }
        }

        return best;
    }
};