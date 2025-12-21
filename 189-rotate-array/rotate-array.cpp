class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        vector<int> helper(n);

        for(int i=0; i<n; i++) {
            if(i+k<n) {
                helper[i+k]=nums[i];
            }else {
                int tempIndex=i+k-n;

                helper[tempIndex]=nums[i];
            }
        }

        for(int i=0; i<n; i++) {
            nums[i]=helper[i];
        }

        return;
    }
};