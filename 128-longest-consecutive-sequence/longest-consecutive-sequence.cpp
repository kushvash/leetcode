class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> record;
        int maxL=0;

        for(int& num: nums){
            record.insert(num);
        }

        for(auto& num: record){
            if(record.find(num-1)==record.end()){
                int temp=num;
                int len=0;

                while(record.find(temp)!=record.end()){
                    temp++;
                    len++;
                }

                maxL=max(maxL, len);
            }
        }

        return maxL;
    }
};