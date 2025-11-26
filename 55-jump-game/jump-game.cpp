class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) {
            return true;
        }
        vector<bool> visited(n, false);
        visited[0]=true;

        for(int currPos=0; currPos<n; currPos++) {
            if(visited[currPos]==false) {
                return false;
            }

            int finalPos=currPos+nums[currPos];

            if(finalPos>=n-1) {
                return true;
            }

            if(visited[finalPos]) {
                continue;
            }

            for(int tempPos=finalPos; tempPos>=currPos && visited[tempPos]==false; tempPos--) {
                visited[tempPos]=true;
            }
        }

        return false;
    }
};