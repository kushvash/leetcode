class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        if(n==1){
            return 1;
        }
        // vector<int> incA(n);
        // vector<int> decA(n);
        int inc=1, dec=1;

        int res=1;


        for(int i=1; i<n; i++){
            if(arr[i]>arr[i-1]){
                inc=dec+1;
                dec=1;
            }
            else if(arr[i]<arr[i-1]){
                dec=inc+1;
                inc=1;
            }else{
                dec=1;
                inc=1;
            }

            res=max(res, max(inc, dec));
        }

        return res;


    }
};