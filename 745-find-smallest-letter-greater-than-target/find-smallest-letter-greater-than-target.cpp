class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int lo=0, hi=letters.size()-1, mid;

        while(lo<=hi){
            mid=lo+(hi-lo)/2;

            if(letters[mid]>target){
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        } 

        if(lo==letters.size()){
            lo=0;
        }
        return letters[lo];
    }
};