class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);
       
        for(int i=0; i<s1.size(); i++) {
            s1Count[s1[i]-'a']++;
            s2Count[s2[i]-'a']++;
        }

        int matches=0;

        for(int i=0; i<26; i++) {
            if(s1Count[i]==s2Count[i]) {
                matches++;
            }
        }

        int l=0, r=s1.size();

        while(r<s2.size()) {
            if(matches==26) {
                return true;
            }

            int index=s2[l]-'a';
            s2Count[index]--;

            if(s1Count[index]==s2Count[index]) {
                matches++;
            }else if(s1Count[index]==s2Count[index]+1) {
                matches--;
            }


            index=s2[r]-'a';
            s2Count[index]++;

            if(s1Count[index]==s2Count[index]) {
                matches++;
            }else if(s1Count[index]==s2Count[index]-1) {
                matches--;
            }

            l++;
            r++;
        }

        return matches==26;
    }
};