class Solution {
public:
    bool checkMaps(vector<int>& rec1, vector<int>& rec2) {
        for(int i=0; i<26; i++) {
            if(rec1[i]!=rec2[i]) {
                return false;
            }
        }

        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size(), n2=s2.size();

        if(n1>n2) {
            return false;
        }

        vector<int> rec1(26, 0);
        vector<int> rec2(26, 0);

        for(int i=0; i<n1; i++) {
            rec1[s1[i]-'a']++;
            rec2[s2[i]-'a']++;
        }

        int left=0, right=n1-1;

        while(right<n2) {
            if(checkMaps(rec1, rec2)) {
                return true;
            }

            rec2[s2[left]-'a']--;
            left++;
            right++;
            if(right<n2) {
                rec2[s2[right]-'a']++;
            }
        }

        return false;
    }
};