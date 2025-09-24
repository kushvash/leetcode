class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> res;

        int currMax=0;

        for(int i=heights.size()-1; i>=0; i--) {
            if(heights[i]>currMax) {
                res.push_back(i);
                currMax=heights[i];
            }
        }

        reverse(res.begin(), res.end());

        return res;
    }
};