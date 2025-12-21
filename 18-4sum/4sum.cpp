class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++) {
            if(i>0 && nums[i]==nums[i-1]) {
                continue;
            }
            for(int j=i+1; j<n; j++) {
                if(j>i+1 && nums[j]==nums[j-1]) {
                    continue;
                }

                int left=j+1, right=n-1; 
                long long newTarget=target-(long long)(nums[i]+nums[j]);

                while(left<right) {
                    long long sum=nums[left]+nums[right];

                    if(sum==newTarget) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while(left<right && nums[left]==nums[left+1]) {
                            left++;
                        }
                        left++;
                        right--;
                    }else if(sum>newTarget) {
                        right--;
                    }else {
                        left++;
                    }
                }
            }
        }

        return res;
    }
};

// [-2, -1, 0, 0, 1, 2]