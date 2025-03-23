class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r=height.size()-1, maxV=0;

        while(l<r) {
            maxV=max(maxV, min(height[l], height[r])*(r-l));

            if(height[l]>height[r]) {
                r--;
            }else {
                l++;
            }
        }

        return maxV;
    }
};