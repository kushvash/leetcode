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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        if(!root1 || !root2) {
            return false;
        }
       
       int val1=root1->val, val2=root2->val;

        if(val1+val2==target) {
            return true;
        }else if(val1+val2>target) {
            return (twoSumBSTs(root1->left, root2, target) || twoSumBSTs(root1, root2->left, target));
        }else {
            return (twoSumBSTs(root1->right, root2, target) || twoSumBSTs(root1, root2->right, target));
        }
    }
};