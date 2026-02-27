/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* _helper(vector<int>& nums, int left, int right) {
        if(left>right) {
            return nullptr;
        }

        int mid=(left+right)/2;

        TreeNode* curr=new TreeNode(nums[mid]);

        curr->left=_helper(nums, left, mid-1);
        curr->right=_helper(nums, mid+1, right);

        return curr;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return _helper(nums, 0, nums.size()-1);
    }
};