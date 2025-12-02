class Solution {
public:
    int helper(int n) {
        int res=0;
        while(n>0) {
            int dig=n%10;
            res+=dig*dig;
            n/=10;
        }

        return res;
    }
    bool isHappy(int n) {
        int slow=n, fast=helper(n);

        while(fast!=1) {
            if(slow==fast) {
                return false;
            }
            slow=helper(slow);
            fast=helper(helper(fast));
        }

        return true;
    }
};