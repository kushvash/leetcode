class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;

        // Step 1: Find the index of the smallest element (pivot)
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;  // left-biased
            if (nums[mid] > nums[hi]) {
                // Pivot is to the right of mid
                lo = mid + 1;
            } else {
                // Pivot is at mid or to the left
                hi = mid;
            }
        }
        int pivot = lo;

        // Step 2: Binary search in the correct half
        lo = 0;
        hi = n - 1;

        // Determine which half to search
        if (target >= nums[pivot] && target <= nums[hi]) {
            lo = pivot;
        } else {
            hi = pivot - 1;
        }

        // Standard binary search
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            
            if(nums[mid]>=target){
                hi=mid;
            }else{
                lo=mid+1;
            }

        }

        if(nums[lo]==target){
            return lo;
        }

        return -1; // Not found



    }
};