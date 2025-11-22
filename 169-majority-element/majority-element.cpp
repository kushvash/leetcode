class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> count;

        for(int num: nums) {
            count[num]++;

            if(count[num]>n/2) {
                return num;
            }
        }

        return -1;
    }
};