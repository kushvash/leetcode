class Solution {
public:
    int findMaxF(unordered_map<char, int>& record){
        int maxF=0;
        for(auto i: record){
            maxF=max(maxF, i.second);
        }

        return maxF;
    }
    int characterReplacement(string s, int k) {
        int l=0, r=0, maxL=0;
        unordered_map<char, int> record;

        while(r<s.size()){
            record[s[r]]++;
            while((r-l+1)-findMaxF(record)>k) {
                record[s[l]]--;
                l++;
            }
            maxL=max(maxL, r-l+1);
            r++;
        }

        return maxL;
    }
};