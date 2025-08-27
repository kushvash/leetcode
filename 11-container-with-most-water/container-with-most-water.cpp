class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r=height.size()-1, maxC=0;

        while(l<r){
            int temp=min(height[l], height[r])*(r-l);
            if(height[l]<height[r]){
                l++;
                maxC=max(maxC, temp);
            }else{
                r--;
                maxC=max(maxC, temp);
            }
        }

        return maxC;
    }
};