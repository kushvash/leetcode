class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax=0, rightMax=0, left=0, right=height.size()-1, res=0;

        while(left<right) {
            if(height[left]>height[right]) {
                if(height[right]>=rightMax) {
                    rightMax=height[right];
                }else {
                    res+=rightMax-height[right];
                }
                right--;
            }else {
                if(height[left]>=leftMax) {
                    leftMax=height[left];
                }else {
                    res+=leftMax-height[left];
                }
                left++;
            }
        }

        return res;
    }
};