class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxCount=0, c=0;

        for(int i: nums) {
            mp[i]++;
            maxCount=max(maxCount, mp[i]);    
        }

        for(const auto& [num, count]: mp) {
            if(count==maxCount) {
                c++;
            }
        }

        return c*maxCount;
    }
};