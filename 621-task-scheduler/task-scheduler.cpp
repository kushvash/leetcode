class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0){
            return tasks.size();
        }

        vector<int> count(26, 0);

        for(char c: tasks){
            count[c-'A']++;
        }

        priority_queue<int> pq;

        for(int i: count){
            if(i>0){
                pq.push(i);
            }
        }

        queue<pair<int, int>> q;
        
        int time=0;

        while(!pq.empty() || !q.empty()){
            time++;

            if(pq.empty()){
                time=q.front().second;
            }else{
                int cnt=pq.top()-1;
                pq.pop();
                if(cnt>0){
                    q.push({cnt, time+n});
                }
            }

            if(!q.empty() && q.front().second==time){
                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};