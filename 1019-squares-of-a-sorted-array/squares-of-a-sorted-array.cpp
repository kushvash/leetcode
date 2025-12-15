class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left=0, right=nums.size()-1, n=nums.size();
        vector<int> res(n, 0);
        n--;

        while(left<=right) {
            if(nums[left]*nums[left]>nums[right]*nums[right]) {
                res[n]=nums[left]*nums[left];
                left++;
            }else {
                res[n]=nums[right]*nums[right];
                right--;
            }
            n--;
        }

        return res;
    }
};