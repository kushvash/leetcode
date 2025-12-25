class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> modFreq;
        modFreq[0]=1;

        int sumMod=0, res=0;
        
        for(int num: nums) {
            sumMod+=num;
            sumMod%=k;

            if(sumMod<0) {
                sumMod+=k;
            }

            if(modFreq.find(sumMod)!=modFreq.end()) {
                res+=modFreq[sumMod];
            }

            modFreq[sumMod]++;
        }

        return res;
    }
};