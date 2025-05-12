class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>> helper(n+1);
        unordered_map<int, int> helperMap;
        vector<int> ans;

        for(int num: nums){
            helperMap[num]++;
        }

        for(auto i: helperMap){
            helper[i.second].push_back(i.first);
        }

        for(int i=n; i>=0; i--){
            vector<int> vec=helper[i];
            for(int i: vec){
                ans.push_back(i);
                if(ans.size()==k){
                    return ans;
                }
            }
            
        }

        return ans;
        
    }
};