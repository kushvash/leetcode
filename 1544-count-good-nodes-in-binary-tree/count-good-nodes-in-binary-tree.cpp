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
    void goodNodesHelper(TreeNode* node, int maxEle, int& res) {
        if(!node) {
            return;
        }

        if(node->val>=maxEle) {
            res++;
        }

        goodNodesHelper(node->left, max(maxEle, node->val), res);
        goodNodesHelper(node->right, max(maxEle, node->val), res);        
    }

    int goodNodes(TreeNode* root) {
        int res=0;

        goodNodesHelper(root, INT_MIN, res);

        return res;
    }
};