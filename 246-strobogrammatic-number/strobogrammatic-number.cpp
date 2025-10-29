class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> mp={
            {'8', '8'},
            {'6', '9'}, 
            {'9', '6'},
            {'1', '1'},
            {'0', '0'}
        };

        int l=0, r=num.size()-1;

        while(l<=r) {
            if(mp.find(num[l])==mp.end() || mp.find(num[r])==mp.end() || mp[num[l]]!=num[r]) {
                return false;
            }
            l++;
            r--;
        }

        return true;
    }
};