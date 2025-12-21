class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int n=nums.size();
        long long res=nums[0]+nums[1]+nums[2];

        for(int i=0; i<n-2; i++) {
            int left=i+1, right=n-1;

            while(left<right) {
                long long currSum=nums[i]+nums[left]+nums[right];
                if(abs(target-res)>abs(target-currSum)) {
                    res=currSum;
                }
                if(res==target) {
                    return res;
                }
                if(currSum>target) {
                    right--;
                }else {
                    left++;
                }
            }
        }

        return res;
    }
};