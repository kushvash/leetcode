class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> record;
        int ans=0;

        for(int& num: nums){
            record.insert(num);
        }

        for(auto& i: record){
            if(record.find(i-1)==record.end()){
                int currC=1;
                int currN=i;

                while(record.find(currN+1)!=record.end()){
                    currC++;
                    currN++;
                }

                ans=max(ans, currC);
            }
        }

        return ans;
    }
};