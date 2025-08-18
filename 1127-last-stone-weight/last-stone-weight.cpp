class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int stone: stones){
            pq.push(stone);
        }

        while(pq.size()>1){
            int s1, s2;
            s1=pq.top();
            pq.pop();
            s2=pq.top();
            pq.pop();

            if(s2<s1){
                pq.push(s1-s2);
            }
        }

        pq.push(0);
        return pq.top();
    }
};