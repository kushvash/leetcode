class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int left=0, mid=0, right, n=nums.size()-1;
        vector<vector<int>> ans;
        set<vector<int>> set;
        
        right=n;

        while(left<nums.size()-1){
            if(nums[left]>0){
                break;
            }

            mid=left+1;
            right=n;
            while(mid<right){
                if(nums[left]+nums[mid]+nums[right]==0){
                    set.insert({nums[left], nums[mid], nums[right]});
                    right--;
                    mid++;
                }else if(nums[left]+nums[mid]+nums[right]>0){
                    right--;
                }else{
                    mid++;
                }
            }
            left++;
        }
        for(auto it : set){
            ans.push_back(it);
        }
        return ans;
    }
};