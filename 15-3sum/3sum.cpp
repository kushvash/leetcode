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
            start=i+1;
            end=n-1;

            while(start<end) {
                if(nums[i]+nums[start]+nums[end]==0){
                    helper.insert({nums[i], nums[start], nums[end]});
                    start++;
                    end--;
                }
                else if(nums[i]+nums[start]+nums[end]>0){
                    end--;
                }else {
                    start++;
                }
            }
        }

        for(auto it: helper) {
            ans.push_back(it);
        }


        return ans;
    }
};