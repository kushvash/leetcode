class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size(), maxA=1, inc=1, dec=1;
        if(n==1){
            return 1;
        }

        for(int i=1; i<n; i++){
            if(arr[i]>arr[i-1]){
                inc=dec+1;
                dec=1;
            }else if(arr[i]<arr[i-1]){
                dec=inc+1;
                inc=1;
            }else {
                inc=1;
                dec=1;
            }

            maxA=max(maxA, max(inc, dec));
        }

        return maxA;
    }
};