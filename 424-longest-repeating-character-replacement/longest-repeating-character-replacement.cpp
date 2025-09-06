class Solution {
public:
    int maxCountIn(unordered_map<char, int>& record) {
        int maxC=0;

        for(auto& [c, i]:record) {
            maxC=max(maxC, i);
        }

        return maxC;
    }

    int characterReplacement(string s, int k) {
        int left=0, right=0, maxCount=0, n=s.size();
        unordered_map<char, int> record;

        while(right<n) {
            record[s[right]]++;
            while(((right-left+1)-maxCountIn(record))>k) {
                record[s[left]]--;
                left++;
            }

            maxCount=max(maxCount, right-left+1);
            right++;
        }

        return maxCount;
    }
};