class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});

        for(int i=1; i<numRows; i++){
            vector<int> curr;
            for(int j=0; j<=i; j++){
                if(j==0 || j==i){
                    curr.push_back(1);
                }else{
                    int temp=ans[i-1][j]+ans[i-1][j-1];
                    curr.push_back(temp);
                }
            }

            ans.push_back(curr);
        }

        return ans;
    }
};