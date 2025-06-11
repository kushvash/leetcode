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
    int maxPathSumHelper(TreeNode* node, int& maxS) {
        if(!node){
            return 0;
        }

        int l=maxPathSumHelper(node->left, maxS);
        int r=maxPathSumHelper(node->right, maxS);

        maxS=max(maxS, l+r+node->val);

        return max(0, node->val+max(l, r));
    }

    int maxPathSum(TreeNode* root) {
        int maxS=root->val;

        maxPathSumHelper(root, maxS);

        return maxS;
    }
};