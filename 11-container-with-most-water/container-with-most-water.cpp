class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0, right=height.size()-1, maxV=0;

        while(left<right){
            if(height[left]>height[right]){
                maxV=max(maxV, height[right]*(right-left));
                right--;
            }else{
                maxV=max(maxV, height[left]*(right-left));
                left++;
            }
        }

        return maxV;
    }
};