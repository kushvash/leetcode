class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq;
        int n = score.size();

        for (int i = 0; i < n; i++) {
            pq.push({score[i], i});
        }

        vector<string> res(n);

        int rank = 1;

        while (!pq.empty()) {
            // int s=pq.top().first;
            int i=pq.top().second;
            pq.pop();
            string input;

            if (rank == 1) {
                input = "Gold Medal";
            } else if (rank == 2) {
                input = "Silver Medal";
            } else if (rank == 3) {
                input = "Bronze Medal";
            } else {
                input = to_string(rank);
            }

            rank++;

            res[i] = input;
        }

        return res;
    }
};