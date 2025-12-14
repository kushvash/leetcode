class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> record;
        int res=0;

        for(int& num: nums) {
            record.insert(num);
        }

        for(int num: record) {
            if(record.find(num-1)==record.end()) {
                int tempNum=num, currLen=0;
                while(record.find(tempNum)!=record.end()) {
                    tempNum++;
                    currLen++;
                }

                res=max(currLen, res);
            }
        }

        return res;
    }
};