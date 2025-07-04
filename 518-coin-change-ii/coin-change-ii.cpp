#include <vector>
// #include <boost/multiprecision/cpp_int.hpp>
// using boost::multiprecision::cpp_int;
using namespace std;


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();

        vector<vector<uint>> dp(n+1, vector<uint>(amount+1, 0));

        for(int i=0; i<=n; i++){
            dp[i][0]=1;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=amount; j++){
                if(coins[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
                }
            }
        }

        return dp[n][amount];
    }
};