class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        int mid, last;

        for(int start=0; start<nums.size(); start++){
            if (nums[start] > 0) break;
            if (start > 0 && nums[start] == nums[start - 1]) continue;

            mid=start+1;
            last=nums.size()-1;

            while(mid<last){
                if(nums[start]+nums[mid]+nums[last]<0){
                    mid++;
                }else if(nums[start]+nums[mid]+nums[last]>0){
                    last--;
                }else{
                    ans.push_back({nums[start], nums[mid], nums[last]});
                    mid++;
                    last--;
                    while (mid < last && nums[mid] == nums[mid - 1]) {
                        mid++;
                    }     
                }
            }
        }

        return ans;
    }
};