class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        if(n==1){
            return 1;
        }
        vector<int> incA(n);
        vector<int> decA(n);

        incA[0]=decA[0]=1;
        int res=1;


        for(int i=1; i<n; i++){
            if(arr[i]>arr[i-1]){
                incA[i]=decA[i-1]+1;
                decA[i]=1;
            }
            else if(arr[i]<arr[i-1]){
                decA[i]=incA[i-1]+1;
                incA[i]=1;
            }else{
                decA[i]=1;
                incA[i]=1;
            }

            res=max(res, max(incA[i], decA[i]));
        }

        return res;


    }
};