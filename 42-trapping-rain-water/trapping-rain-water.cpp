class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int leftMax = height[l], rightMax = height[r];
        int res = 0;
        while (l < r) {
            if (leftMax < rightMax) {
                l++;
                int temp=leftMax - height[l];
                res += max(temp, 0);
                leftMax = max(leftMax, height[l]);
            } else {
                r--;
                int temp=rightMax - height[r];
                res += max(temp, 0);
                rightMax = max(rightMax, height[r]);
            }
        }
        return res;
    }
};