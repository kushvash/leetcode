class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev;
        prev.push_back({1});

        for(int i=1; i<=rowIndex; i++){
            vector<int> curr;
            for(int j=0; j<=i; j++){
                if(j==0 || j==i){
                    curr.push_back(1);
                }else{
                    int temp=prev[j]+prev[j-1];
                    curr.push_back(temp);
                }
            }

            prev=curr;
        }

        return prev;
    }
};