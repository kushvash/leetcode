class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxC=0;
        vector<bool> ans;

        for(int candy: candies){
            maxC=max(maxC, candy);
        }

        for(int candy: candies){
            ans.push_back(candy+extraCandies>=maxC);
        }

        return ans;
    }
};