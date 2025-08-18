class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        unordered_map<char, int> record;

        for(int i=0; i<n; i++){
            record[s[i]]=i;
        }

        vector<int> ans;
        int size=0, end=0;

        for(int i=0; i<n; i++){
            size++;
            end=max(end, record[s[i]]);

            if(i==end){
                ans.push_back(size);
                size=0;
            }
        }

        return ans;
    }
};