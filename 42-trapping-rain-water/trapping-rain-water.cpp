class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(), ans=0;
        int maxL=height[0], maxR=height[n-1], l=0, r=n-1;

        while(l<r){
            if(maxL<maxR){
                l++;
                ans+=max(0, maxL-height[l]);
                maxL=max(maxL, height[l]);
            }else{
                r--;
                ans+=max(0, maxR-height[r]);
                maxR=max(maxR, height[r]);
            }
        }

        return ans;
    }
};