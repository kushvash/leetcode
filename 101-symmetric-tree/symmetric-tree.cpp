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
    bool isSymmetric(TreeNode* root) {
        queue<pair<TreeNode*, TreeNode*>> q;

        q.push({root->left, root->right});

        while(!q.empty()) {
            auto [leftN, rightN]=q.front();
            q.pop();

            if(!leftN && !rightN) {
                continue;
            }

            if(!leftN || !rightN || leftN->val!=rightN->val) {
                return false;
            }

            q.push({leftN->left, rightN->right});
            q.push({leftN->right, rightN->left});
        }

        return true;
    }
};