class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        queue<pair<int, int>> q;
        int time=0;
        unordered_map<char, int> map;

        for(char& c: tasks) {
            map[c]++;
        }

        for(auto& [_, cnt]: map) {
            pq.push(cnt);
        }

        while(!pq.empty() || !q.empty()) {
            if(pq.empty()) {
                if(q.front().second>time) {
                    time = q.front().second;
                }
            }

            while (!q.empty() && q.front().second <= time) {
                pq.push(q.front().first);
                q.pop();
            }

            if (!pq.empty()) {
                int cnt = pq.top(); 
                pq.pop();     
                cnt--;
                if (cnt > 0) {
                    q.push({cnt, time + n + 1});
                }
            }

            time++;
        }

        return time;
    }
};