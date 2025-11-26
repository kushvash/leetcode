class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump=0, n=nums.size();
        if(maxJump>=n-1) {
            return true;
        }

        for(int i=0; i<n; i++) {
            if(i>maxJump) {
                return false;
            }
            int currMaxJump=i+nums[i];
            maxJump=max(maxJump, currMaxJump);

            if(maxJump>=n-1) {
                return true;
            }
        }

        return false;
    }
};