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
    TreeNode* toBST(int start, int end, vector<int>& nums) {
        if(start>end){
            return nullptr;
        }
        int mid=start+(end-start)/2;

        TreeNode *root = new TreeNode(nums[mid]);

        root->left=toBST(start, mid-1, nums);
        root->right=toBST(mid+1, end, nums);

        return root;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int end=nums.size()-1;

        return toBST(0, end, nums);
    }
};