class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size(), n2=s2.size();

        if(n1>n2) {
            return false;
        }

        vector<int> record1(26, 0);
        vector<int> record2(26, 0);

        for(int i=0; i<n1; i++) {
            char c=s1[i];
            record1[c-'a']++;
        }

        int left=0, right=0, res=0;

        while(right<n1) {
            char cR=s2[right];
            record2[cR-'a']++;
            right++;
        }

        for(int i=0; i<26; i++) {
            if(record1[i]==record2[i]) {
                res++;
            }
        }

        if(res==26) {
            return true;
        }

        while(right<n2) {
            int add = s2[right] - 'a';
            int rem = s2[left] - 'a';
            left++;

            if(record2[add] == record1[add]) {
                res--;
            }
            
            record2[add]++;
            
            if(record2[add] == record1[add]) {
                res++;
            }

            if(record2[rem] == record1[rem]) {
                res--;
            }

            record2[rem]--;

            if(record2[rem] == record1[rem]) {
                res++;
            }

            if (res == 26) {
                return true;
            }

            right++;
        }

        return false;
    }
};