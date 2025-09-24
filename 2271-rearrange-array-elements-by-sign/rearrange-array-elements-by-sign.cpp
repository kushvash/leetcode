class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos=0, neg=0;
        vector<int> res;

        while(nums[pos]<0) {
            pos++;
        }
        while(nums[neg]>0) {
            neg++;
        }

        while(res.size()!=nums.size()) {
            res.push_back(nums[pos]);
            pos++;
            res.push_back(nums[neg]);
            neg++;
            while(pos<nums.size() && nums[pos]<0) {
                pos++;
            }
            while(neg<nums.size() && nums[neg]>0) {
                neg++;
            }            
        }

        return res;
    }
};