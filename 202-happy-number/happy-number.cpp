class Solution {
public:
    int isHappyHelper(int n) {
        int ans=0;

        while(n>0){
            int temp=(n%10);
            ans+=temp*temp;
            n/=10;
        }

        return ans;
    }
    bool isHappy(int n) {
        int slow=isHappyHelper(n);
        int fast=isHappyHelper(isHappyHelper(n));

        while(slow!=fast){
            if(fast==1){
                return true;
            }
            slow=isHappyHelper(slow);
            fast=isHappyHelper(isHappyHelper(fast));
        }

        return slow==1;
    }
};