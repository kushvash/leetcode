class Solution {
public:
    int reverse(int x) {
        bool neg=false;
        long ans=0;

        if(x==INT_MIN){
            return 0;
        }

        if(x<0){
            x*=-1;    
            neg=true;
        }

        while(x>0){
            ans*=10;
            if(ans>INT_MAX){
                return 0;
            }
            ans+=x%10;
            x/=10;
        }

        if(neg){
            return -ans;
        }
        return ans;
    }
};