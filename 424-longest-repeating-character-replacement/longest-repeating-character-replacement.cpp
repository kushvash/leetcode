class Solution {
public:
    int mostFreq(unordered_map<char, int>& freqMap) {
        int res=0;

        for(auto& [c, i]: freqMap) {
            res=max(res, i);
        }

        return res;
    }

    int characterReplacement(string s, int k) {
        int n=s.size(), left=0, right=0, res=0;

        unordered_map<char, int> freqMap;

        while(right<n) {
            freqMap[s[right]]++;

            while((right-left+1)-mostFreq(freqMap)>k) {
                freqMap[s[left]]--;
                left++;
            }

            res=max(res, right-left+1);
            right++;
        }

        return res;
    }
};