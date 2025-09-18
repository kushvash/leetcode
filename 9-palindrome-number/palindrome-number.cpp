class Solution {
public:
    bool isPalindromeS(vector<int> s) {
        int n=s.size()-1;

        for(int i=0; i<n; i++) {
            if(s[i]!=s[n]) {
                return false;
            }
            n--;
        }

        return true;
    }
    bool isPalindrome(int x) {
        if(x<0) {
            return false;
        }

        vector<int> s;

        while(x>0) {
            s.push_back(x%10);
            x/=10;
        }

        return isPalindromeS(s); 
    }
};