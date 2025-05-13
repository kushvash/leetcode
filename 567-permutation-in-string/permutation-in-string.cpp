class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){
            return false;
        }

        // unordered_map<char, int> m1, m2;

        vector<int> m1(26,0), m2(26,0);

        int matches=0, end=s1.size(), start=0;

        for(int i=0; i<s1.size(); i++){
            // m1[s1[i]]++;
            // m2[s2[i]]++;

            m1[s1[i]-'a']++;
            m2[s2[i]-'a']++;
        }

        for(int i=0; i<26; i++){
            if(m1[i]==m2[i]){
                matches++;
            }
        }

        while(end<s2.size()){
            if(matches==26){
                return true;
            }

            m2[s2[end]-'a']++;
            if(m2[s2[end]-'a']==m1[s2[end]-'a']){
                matches++;
            }else if(m2[s2[end]-'a']==m1[s2[end]-'a']+1){
                matches--;
            }

            m2[s2[start]-'a']--;
            if(m2[s2[start]-'a']==m1[s2[start]-'a']){
                matches++;
            }else if(m2[s2[start]-'a']==m1[s2[start]-'a']-1){
                matches--;
            }

            start++;
            end++;
        }

        return matches==26;

    }
};