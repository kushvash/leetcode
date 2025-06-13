class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0], nums[1]);
        }

        vector<int> record(n);
        
        record[n-1]=nums[n-1];
        record[n-2]=max(nums[n-1], nums[n-2]);

        for(int i=n-3; i>=0; i--){
            record[i]=max(nums[i]+record[i+2], record[i+1]);
        }

        return record[0];
    }
};