class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1, k=1;

        while(i<nums.size()){
            if(nums[i]!=nums[i-1]){
                nums[k]=nums[i];
                k++;
            }
            i++;
        }

        return k;
    }
};