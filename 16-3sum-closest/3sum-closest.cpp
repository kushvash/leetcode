class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n=nums.size(), res=nums[0]+nums[1]+nums[2];

        for(int lo=0; lo<n-2; lo++) {
            int mid=lo+1;
            int hi=nums.size()-1;

            while(mid<hi) {
                int newRes=nums[lo]+nums[mid]+nums[hi];

                if(newRes==target) {
                    return newRes;
                }else if(abs(target-res)>abs(target-newRes)) {
                    res=newRes;
                }

                if(newRes>target) {
                    hi--;
                }else {
                    mid++;
                }
            }
        }

        return res;
    }
};