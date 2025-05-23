class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int count=0, l=0, r=people.size()-1;
        sort(people.begin(), people.end());

        while(l<=r) {
            if(people[l]+people[r]<=limit){
                l++;
            }    
            count++;
            r--;
        }


        return count;
    }
};