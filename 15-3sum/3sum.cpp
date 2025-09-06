class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int right, mid, n=nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for(int left=0; left<n-2; left++) {
            if(left>0 && nums[left-1]==nums[left]) {
                continue;
            }

            mid=left+1;
            right=n-1;

            while(mid<right) {
                int num1=nums[left], num2=nums[mid], num3=nums[right];
                if(num1+num2+num3>0) {
                    right--;
                }else if(num1+num2+num3<0) {
                    mid++;
                }else {
                    ans.push_back({num1, num2, num3});
                    mid++;
                    while(mid<right && (nums[mid]==nums[mid-1])) {
                        mid++;
                    }
                    right--;
                }
            }
        }

        return ans;
    }
};