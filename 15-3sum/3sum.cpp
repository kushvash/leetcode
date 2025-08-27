class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size(), l, r;
        vector<vector<int>> ans;

        for(int i=0; i<n-2; i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }

            l=i+1;
            r=n-1;

            while(l<r){
                int temp=nums[i]+nums[l]+nums[r];

                if(temp>0){
                    r--;
                }else if(temp<0){
                    l++;
                }else{
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while(l<r && nums[l]==nums[l-1]){
                        l++;
                    }
                }
            }
        }

        return ans;
    }
};