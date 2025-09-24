class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int iP=0, iT=0, res=0;
    
        while(iP<players.size() && iT<trainers.size()) {
            if(trainers[iT]>=players[iP]) {
                res++;
                iP++;
                iT++;
            }else {
                iT++;
            }
        }

        return res;
    }
};