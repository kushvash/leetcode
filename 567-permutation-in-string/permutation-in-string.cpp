class Solution {
public:
    bool checkInclusion(string s1, string s2){
        if (s1.length() > s2.length()) return false;

        int right=s1.length(), left=0;
        vector<int> s1map(26,0); 
        vector<int> s2map(26,0);

        for(char c: s1){
            s1map[c-'a']++;
        }

        for(int i=0; i<s1.length(); i++){
            s2map[s2[i]-'a']++;
        }

        if(s1map==s2map){
            return true;
        }

        while(right<s2.length()){
            s2map[s2[right]-'a']++;
            s2map[s2[left]-'a']--;

            if(s1map==s2map){
                return true;
            }

            left++;
            right++;
        }

        return false;
    }
};