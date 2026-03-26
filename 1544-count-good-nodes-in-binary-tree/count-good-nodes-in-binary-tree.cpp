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
    void _goodNodesHelper(TreeNode* node, int currMax, int& res) {
        if(!node) {
            return;
        }

        if(node->val>=currMax) {
            res++;
            currMax=node->val;
        }

        _goodNodesHelper(node->left, currMax, res);
        _goodNodesHelper(node->right, currMax, res);
    }

    int goodNodes(TreeNode* root) {
        int res=1;

        _goodNodesHelper(root->left, root->val, res);
        _goodNodesHelper(root->right, root->val, res);

        return res;
    }
};