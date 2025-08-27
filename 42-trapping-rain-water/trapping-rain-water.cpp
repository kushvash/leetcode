class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();

        vector<int> maxL(n, 0);
        vector<int> maxR(n, 0);
        
        int temp=height[0];
        for(int i=1; i<n; i++){
            maxL[i]=temp;
            temp=max(temp, height[i]);    
        }

        temp=height[n-1];
        for(int i=n-2; i>=0; i--){
            maxR[i]=temp;
            temp=max(temp, height[i]);    
        }

        int ans=0;
        for(int i=0; i<n; i++){
            temp=min(maxL[i], maxR[i])-height[i];
            ans+=max(temp, 0);
        }

        return ans;
    }
};