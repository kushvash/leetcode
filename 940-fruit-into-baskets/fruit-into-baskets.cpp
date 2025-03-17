class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left=0, right=0, maxP=0;
        unordered_map<int, int> helper;

        while(right<fruits.size()){
            if(helper.find(fruits[right])==helper.end() && helper.size()>1){
                while(helper.size()!=1){
                    helper[fruits[left]]--;
                    left++;
                    if(helper[fruits[left-1]]==0){
                        helper.erase(fruits[left-1]);
                    }
                }
            }
            helper[fruits[right]]++;
            right++;

            int count=0;
            for(auto it:helper){
                count+=it.second;
            }

            maxP=max(maxP, count);
        }

        return maxP;
    }
};