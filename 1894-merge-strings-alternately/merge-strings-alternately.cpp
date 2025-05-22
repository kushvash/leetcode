class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s="";
        int n1=word1.size(), n2=word2.size(), i1=0, i2=0;

        while(i1<n1 && i2<n2){
            s.push_back(word1[i1]);
            s.push_back(word2[i2]);

            i1++;
            i2++;
        }

        while(i1<n1){
            s.push_back(word1[i1]);
            // s.push_back(word2[i2]);

            i1++;
            // i2++;
        }
        while(i2<n2){
            // s.push_back(word1[i1]);
            s.push_back(word2[i2]);

            // i1++;
            i2++;
        }

        return s;

    }
};