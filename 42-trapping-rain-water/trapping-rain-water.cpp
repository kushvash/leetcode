class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(), res=0;
        vector<int> maxL(n, 0);
        vector<int> maxR(n, 0);

        for(int i=1; i<n; i++) {
            maxL[i]=max(maxL[i-1], height[i-1]);
            maxR[n-i-1]=max(maxR[n-i], height[n-i]);
        }

        for(int i=1; i<n-1; i++) {
            res+=max(min(maxL[i], maxR[i])-height[i], 0);
        }

        return res;
    }
};