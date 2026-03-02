class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        auto cmp=[&matrix](pair<int, int>& a, pair<int, int>& b) {
            return matrix[a.first][a.second]>matrix[b.first][b.second];
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        int n=matrix.size();

        for(int i=0; i<n; i++) {
            pq.push({i, 0});
        }

        int count=0;

        while(!pq.empty()) {
            auto curr=pq.top();
            pq.pop();

            count++;

            if(count==k) {
                return matrix[curr.first][curr.second];
            }

            if(curr.second<matrix[0].size()-1) {
                pq.push({curr.first, curr.second+1});
            }
        }

        return -1;
    }
};