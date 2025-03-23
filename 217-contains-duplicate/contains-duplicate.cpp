class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> helper;

        for(auto it: nums) {
            if(helper.find(it)!=helper.end()) {
                return true;
            }
            helper.insert(it);
        }

        return false;
    }
};