class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size()==0) {
            return 0;
        }
        
        sort(nums.begin(), nums.end());

        int curr=nums[0], l=1, maxL=1;

        for(int i=1; i<nums.size(); i++) {
            if(nums[i]==curr){
                continue;
            }
            if(nums[i]==curr+1) {
                curr++;
                l++;
                maxL=max(l, maxL);
            }
            else {
                curr=nums[i];
                l=1;
            }
        }

        return maxL;
    }
};