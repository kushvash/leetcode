class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> record;
        int maxSeq=0;

        for(int num: nums){
            record.insert(num);
        }

        for(int i: record){
            if(record.find(i-1)==record.end()){
                int currSeq=1;
                int currNum=i;
                while(record.find(currNum+1)!=record.end()){
                    currNum++;
                    currSeq++;
                }
                maxSeq=max(maxSeq, currSeq);
            }
        }

        return maxSeq;
    }
};