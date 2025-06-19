class Solution {
public:
    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     if (n == 1) 
    //         return nums[0];
    //     if (n == 2) 
    //         return max(nums[0], nums[1]);

    //     // Pass A: consider houses [0…n-2]
    //     int ll = nums[0], l = nums[1];
    //     for (int i = 2; i < n - 1; ++i) {
    //         int temp = max(ll + nums[i], l);
    //         ll = l;
    //         l = temp;
    //     }
    //     int maxP = max(ll, l);        // ← fix: take max of the two

    //     // Pass B: consider houses [1…n-1]
    //     ll = nums[1];
    //     l  = nums[2];
    //     for (int i = 3; i < n; ++i) {
    //         int temp = max(ll + nums[i], l);
    //         ll = l;
    //         l = temp;
    //     }
    //     int maxQ = max(ll, l);        // ← same fix here

    //     return max(maxP, maxQ);
    // }



    int robLinear(const vector<int>& nums, int lo, int hi) {
        int prev2 = 0;  // max up to i–2
        int prev1 = 0;  // max up to i–1
        for (int i = lo; i <= hi; ++i) {
            int cur = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        // case A: exclude last house
        int a = robLinear(nums, 0, n - 2);
        // case B: exclude first house
        int b = robLinear(nums, 1, n - 1);

        return max(a, b);
    }
};