class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxH=0, curr=0;

        for(int h:gain){
            curr+=h;
            maxH=max(maxH, curr);
        }

        return maxH;
    }
};