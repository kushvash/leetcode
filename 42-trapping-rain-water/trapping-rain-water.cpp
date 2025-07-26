class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(), currMax=0, ans=0;

        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);


        currMax=height[0];
        for(int i=1; i<n; i++){
            currMax=max(currMax, height[i]);
            leftMax[i]=currMax;
        }

        currMax=height[n-1];
        for(int i=n-2; i>=0; i--){
            currMax=max(currMax, height[i]);
            rightMax[i]=currMax;
        }

        for(int i=0; i<n; i++){
            int temp=min(leftMax[i], rightMax[i])-height[i];
            if(temp>0){
                ans+=temp;
            }
        }

        return ans;

    }
};