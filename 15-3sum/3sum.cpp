class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        for(int l=0; l<n-2; l++) {
            if(l>0 && nums[l]==nums[l-1]) {
                continue;
            }

            int mid=l+1, r=n-1;
            
            while(mid<r) {
                if(r<n-1 && nums[r]==nums[r+1]) {
                    r--;
                    continue;
                }if(mid>l+1 && nums[mid]==nums[mid-1]) {
                    mid++;
                    continue;
                } 

                if(nums[l]+nums[mid]+nums[r]==0) {
                    res.push_back({nums[l], nums[mid], nums[r]});
                    mid++;
                    r--;
                }else if(nums[l]+nums[mid]+nums[r]>0) {
                    r--;
                }else {
                    mid++;
                }
            }
        }

        return res;
    }
};