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
        if(l<0){
            l=0;
        }
        if(r<0){
            r=0;
        }

        maxS=max(maxS, l+r+node->val);

        return max(l+node->val, r+node->val);
    }

    int maxPathSum(TreeNode* root) {
        int maxS=INT_MIN;
        maxPathSumHelper(root, maxS);
        return maxS;
    }
};