class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;

        for(int i=0; i<n; i++){
            int correct=i+1;

            while(nums[i]!=correct && nums[i]!=nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
            }

        }

        for(int i=0; i<n; i++){
            int correct=i+1;

            if(nums[i]!=correct){
                ans.push_back(correct);
            }
        }

        return ans;
    }
};