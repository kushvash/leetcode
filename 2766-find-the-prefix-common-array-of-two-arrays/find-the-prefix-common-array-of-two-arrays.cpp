class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();

        unordered_set<int> a;
        unordered_set<int> b;
        vector<int> res;

        for(int i=0; i<n; i++) {
            a.insert(A[i]);
            b.insert(B[i]);

            int temp=0;

            for(int i: a) {
                if(b.find(i)!=b.end()) {
                    temp++;
                }
            }

            res.push_back(temp);
        }

        return res;
    }
};