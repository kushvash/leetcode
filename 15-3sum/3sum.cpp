class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int start, end, n=nums.size();
        vector<vector<int>> ans;
        set<vector<int>> helper;

        for(int i=0; i<n; i++) {
            if(nums[i]>0){
                break;
            }
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            start=i+1;
            end=n-1;

            while(start<end) {
                if(nums[i]+nums[start]+nums[end]==0){
                    ans.push_back({nums[i], nums[start], nums[end]});
                    start++;
                    end--;

                    while(nums[start]==nums[start-1] && start<end){
                        start++;
                    }
                }
                else if(nums[i]+nums[start]+nums[end]>0){
                    end--;
                }else {
                    start++;
                }
            }
        }

        return ans;
    }
};