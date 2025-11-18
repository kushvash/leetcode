class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size(), j=0;
        vector<int> res(n, 0);
        bool toInsert=true;

        queue<int> q;
        sort(deck.begin(), deck.end());

        for(int i=0; i<n; i++) {
            q.push(i);
        }

        while(!q.empty()) {
            int insertIndex=q.front();
            q.pop();
            if(toInsert) {
                res[insertIndex]=deck[j];
                toInsert=false;
                j++;
            }else {
                q.push(insertIndex);
                toInsert=true;
            }
        }

        return res;
    }
};