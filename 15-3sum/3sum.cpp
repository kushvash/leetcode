class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size(), target=0;

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        for(int i=0; i<n; i++) {
            if(i>0 && nums[i]==nums[i-1]) {
                continue;
            }

            if(nums[i]>target) {
                break;
            }

            int left=i+1;
            int right=n-1;

            while(left<right) {
                if(left>i+1 && nums[left]==nums[left-1]) {
                    left++;
                    continue;
                }

                int sum=nums[i]+nums[left]+nums[right];

                if(sum==target) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                }else if(sum>target) {
                    right--;
                }else {
                    left++;
                }
            }
        }

        return res;
    }
};