class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int res=0, left=0, right=0, n=fruits.size();
        unordered_map<int, int> fruitCount;

        while(right<n) {
            
            fruitCount[fruits[right]]++;

            while(fruitCount.size()>2) {
                fruitCount[fruits[left]]--;
                if(fruitCount[fruits[left]]==0) {
                    fruitCount.erase(fruits[left]);
                }
                left++;
            }


            res=max(res, right-left+1);

            right++;
        }

        return res;
    }
};