class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> maxL(n, 0);
        vector<int> maxR(n, 0);
        
        maxL[0]=height[0];
        for(int i=1; i<n; i++){
            maxL[i]=max(height[i], maxL[i-1]);
        }

        maxR[n-1]=height[n-1];
        for(int i=n-2; i>=0; i--){
            maxR[i]=max(height[i], maxR[i+1]);
        }
        
        int ans=0;
        for(int i=1; i<n-1; i++){
            int temp=min(maxL[i], maxR[i])-height[i];

            if(temp>0){
                ans+=temp;
            }
        }

        return ans;
    }
};