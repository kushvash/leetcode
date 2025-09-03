class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(), maxP=nums[0];;
        vector<int> maxDP(n, 0);
        vector<int> minDP(n, 0);

        maxDP[0]=minDP[0]=nums[0];

        for(int i=1; i<n; i++) {
            maxDP[i]=max(nums[i], max(maxDP[i-1]*nums[i], minDP[i-1]*nums[i]));
            minDP[i]=min(nums[i], min(maxDP[i-1]*nums[i], minDP[i-1]*nums[i]));

            maxP=max(maxP, maxDP[i]);
        }

        return maxP;
    }
};