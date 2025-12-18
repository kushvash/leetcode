class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0, res=0;

        unordered_map<int, int> modRecord;
    
        modRecord[0]=1;;

        for(int num: nums) {
            sum+=num;
            int modSum=sum%k;

            if(modSum<0) {
                modSum+=k;
            }

            if(modRecord.find(modSum)!=modRecord.end()) {
                res+=modRecord[modSum];
            }

            modRecord[modSum]++;
        }

        return res;
    }
};