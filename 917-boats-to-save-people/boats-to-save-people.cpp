class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int count=0, l=0, r=people.size()-1;
        sort(people.begin(), people.end());

        while(l<r) {
            if(people[l]+people[r]<=limit){
                count++;
                l++;
                r--;
            }else{
                count++;
                r--;
            }
        }

        if(l==r){
            count++;
        }

        return count;
    }
};