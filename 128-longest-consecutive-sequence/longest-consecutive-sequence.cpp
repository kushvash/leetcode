class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        int res=0;

        for(int num: nums) {
            numSet.insert(num);
        }

        for(const int num: numSet) {
            int currCount=0, tempCopy=num;
            if(numSet.find(num-1)==numSet.end()) {
                while(numSet.find(tempCopy)!=numSet.end()) {
                    currCount++;
                    tempCopy++;
                }

                res=max(res, currCount);
            }
        }

        return res;
    }
};