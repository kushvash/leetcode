class Solution {
public:
    int countInRecord(unordered_map<char, int>& record) {
        int maxC=0;

        for(auto& [cha, count]: record) {
            maxC=max(maxC, count);
        }

        return maxC;
    }

    int characterReplacement(string s, int k) {
        int left=0, res=0, n=s.size();

        unordered_map<char, int> record;
    
        for(int right=0; right<n; right++) {
            record[s[right]]++;

            while(right-left+1 - countInRecord(record)>k) {
                record[s[left]]--;
                left++;
            }

            res=max(res, right-left+1);
        }

        return res;
    }
};