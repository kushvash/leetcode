class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int> res(n, 0);
        
        int ballsLeft=0, movesLeft=0, ballsRight=0, movesRight=0;

        for(int i=0; i<n; i++) {
            res[i] += movesLeft;
            ballsLeft += boxes[i] - '0';
            movesLeft += ballsLeft;

            int j = n - 1 - i;
            res[j] += movesRight;
            ballsRight += boxes[j] - '0';
            movesRight += ballsRight;
        }
    
        return res;
    }
};