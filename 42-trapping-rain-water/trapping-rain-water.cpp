class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax=0, rightMax=0, left=0, right=height.size()-1, ans=0;

        leftMax=height[left];
        rightMax=height[right];
        
        while(left<right) {
            if(leftMax>rightMax) {
                right--;
                rightMax=max(rightMax, height[right]);
                ans+=rightMax-height[right];
            }else {
                left++;
                leftMax=max(leftMax, height[left]);
                ans+=leftMax-height[left];
            }
        }

        return ans;
    }
};