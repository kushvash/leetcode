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
    int kthSmallestHelper(TreeNode* node, int k, int& i) {
        if (!node) {
            return -1;
        }

        int l = kthSmallestHelper(node->left, k, i);
        if (l >= 0) {
            return l;
        }

        i++;
        if (i == k) {
            return node->val;
        }

        return kthSmallestHelper(node->right, k, i);
    }

    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        return kthSmallestHelper(root, k, i);
    }
};