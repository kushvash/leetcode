class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zCount=0, oCount=0, tCount=0;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==0) {
                zCount++;
            }else if(nums[i]==1) {
                oCount++;
            }else {
                tCount++;
            }
        }

        for(int i=0; i<nums.size(); i++) {
            if(zCount!=0) {
                nums[i]=0;
                zCount--;
            }else if(oCount!=0) {
                nums[i]=1;
                oCount--;
            }else {
                nums[i]=2;
            }
        }

        return;
    }
};