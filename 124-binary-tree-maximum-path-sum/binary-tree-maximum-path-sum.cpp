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
        int l=max(maxPathSumHelper(node->left, maxS), 0);
        int r=max(maxPathSumHelper(node->right, maxS), 0);

        maxS=max(maxS, l+r+node->val);

        return max(l+node->val, r+node->val);
    }

    int maxPathSum(TreeNode* root) {
        int maxS=INT_MIN;
        maxPathSumHelper(root, maxS);
        return maxS;
    }
};