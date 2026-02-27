class Solution {
public:
    int characterReplacement(string s, int k) {
        int currMax=0, n=s.size(), left=0, res=0;

        vector<int> record(26, 0);

        for(int right=0; right<n; right++) {
            record[s[right]-'A']++;
            
            currMax=max(currMax, record[s[right]-'A']);

            while(right-left+1-currMax>k) {
                record[s[left]-'A']--;
                left++;
            }

            res=max(res, right-left+1);
        }

        return res;
    }
};