class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0, right=height.size()-1, res=0;

        while(left<right) {
            int currWater=(right-left)*min(height[left], height[right]);

            res=max(res, currWater);

            if(height[left]>height[right]) {
                right--;
            }else {
                left++;
            }
        }

        return res;
    }
};