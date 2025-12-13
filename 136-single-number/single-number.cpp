class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> helper;

        for(int& num: nums) {
            if(helper.find(num)==helper.end()) {
                helper.insert(num);
            }else {
                helper.erase(num);
            }
        }

        for(int num: helper) {
            return num;
        }

        return 0;
    }
};