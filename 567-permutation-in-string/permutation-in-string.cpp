class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size(), n2=s2.size(), matches=0, left=0, right=n1;

        if(n1>n2) {
            return false;
        }

        vector<int> s1Freq(26, 0);
        vector<int> s2Freq(26, 0);

        for(int i=0; i<n1; i++) {
            s1Freq[s1[i]-'a']++;
            s2Freq[s2[i]-'a']++;
        }

        for(int i=0; i<26; i++) {
            if(s1Freq[i]==s2Freq[i]) {
                matches++;
            }
        }

        if(matches==26) {
            return true;
        }

        while(right<n2) {
            int add=s2[right]-'a';
            int rem=s2[left]-'a';

            right++;
            left++;

            if(s1Freq[add]==s2Freq[add]) {
                matches--;
            }
            s2Freq[add]++;
            if(s1Freq[add]==s2Freq[add]) {
                matches++;
            }

            if(s1Freq[rem]==s2Freq[rem]) {
                matches--;
            }
            s2Freq[rem]--;
            if(s1Freq[rem]==s2Freq[rem]) {
                matches++;
            }

            if(matches==26) {
                return true;
            }
        }

        return false;
    }
};