class Solution {
public:
    bool isHappy(int n) {
        int slow=n, fast=n;


        slow=squareQ(slow);
        fast=squareQ(squareQ(fast));
        
        while(slow!=fast){
            if(fast==1){
                return true;
            }

            slow=squareQ(slow);
            fast=squareQ(squareQ(fast));
        }

        return slow==1;
    }


// private:
    int squareQ(int n){
        int k, p=0;

        while(n>0){
            k=n%10;
            p+=k*k;
            n/=10;
        }


        return p;
    }
};