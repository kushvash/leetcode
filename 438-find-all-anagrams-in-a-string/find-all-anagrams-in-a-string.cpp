class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;

        int sS=s.size(), pS=p.size(), left=0, right=pS, matches=0;

        if(pS>sS) {
            return {};
        }

        vector<int> pRecord(26, 0);
        vector<int> sRecord(26, 0);

        for(int i=0; i<pS; i++) {
            int ch=p[i]-'a';

            pRecord[ch]++;

            ch=s[i]-'a';

            sRecord[ch]++;
        }

        for(int i=0; i<26; i++) {
            if(pRecord[i]==sRecord[i]) {
                matches++;
            }
        }

        if(matches==26) {
            res.push_back(0);
        }

        while(right<sS) {
            int add=s[right]-'a', rem=s[left]-'a';

            left++, right++;

            if(pRecord[add]==sRecord[add]) {
                matches--;
            }
            sRecord[add]++;
            if(pRecord[add]==sRecord[add]) {
                matches++;
            }

            if(pRecord[rem]==sRecord[rem]) {
                matches--;
            }
            sRecord[rem]--;
            if(pRecord[rem]==sRecord[rem]) {
                matches++;
            }

            if(matches==26) {
                res.push_back(left);
            }
        }

        return res;
    }
};