class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();

        unordered_set<int> a;
        unordered_set<int> b;
        vector<int> res;
        a.insert(A[0]);
        b.insert(B[0]);

        res.push_back(0);

        if(A[0]==B[0]) {
            res[0]=1;
        }

        for(int i=1; i<n; i++) {
            int temp=res[i-1];

            if(a.find(B[i])!=a.end()) {
                temp++;
            }
            if(b.find(A[i])!=b.end()) {
                temp++;
            }
            if(A[i]==B[i]) {
                temp++;
            }

            a.insert(A[i]);
            b.insert(B[i]);

            res.push_back(temp);
        }

        return res;
    }
};