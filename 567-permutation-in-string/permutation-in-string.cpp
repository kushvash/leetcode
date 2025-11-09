class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size(), n2=s2.size(), totalMatched=0, l=0, r=0;

        if(n1>n2) {
            return false;
        }

        vector<int> countS1(26, 0);
        vector<int> countS2(26, 0);

        for(char c: s1) {
            countS1[c-'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (countS1[i] == countS2[i]) {
                totalMatched++;
            }
        }

        for(int i=0; i<n1; i++) {
            char c=s2[i];
            countS2[c-'a']++;
            if(countS2[c-'a']-countS1[c-'a']==0) {
                totalMatched++;
            }else if(countS2[c-'a']-countS1[c-'a']==1) {
                totalMatched--;
            }
            r++;
        }

        if(totalMatched==26) {
            return true;
        }

        while(r<n2) {
            char del=s2[l], ins=s2[r];

            countS2[ins-'a']++;
            if(countS2[ins-'a']-countS1[ins-'a']==0) {
                totalMatched++;
            }else if(countS2[ins-'a']-countS1[ins-'a']==1) {
                totalMatched--;
            }
            r++;
            
            countS2[del-'a']--;
            if(countS2[del-'a']-countS1[del-'a']==0) {
                totalMatched++;
            }else if(countS2[del-'a']-countS1[del-'a']==-1) {
                totalMatched--;
            }
            l++;

            if(totalMatched==26) {
                return true;
            }
        }

        return false;
    }
};