class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        unordered_map<char, int> record;

        for(int i=0; i<n; i++) {
            record[s[i]]=i;
        }

        int lastOccur=record[s[0]], i=0, j=0;
        vector<int> res;

        while(j<n) {
            lastOccur = max(lastOccur, record[s[j]]);
            if(j==lastOccur) {
                res.push_back(j-i+1);
                i=j+1;
            }
            j++;
        }

        return res;
    }
};