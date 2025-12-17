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
    void longestConsecutiveHelper(TreeNode* node, int currLen, int& res) {
        int val=node->val;

        res=max(res, currLen);

        if(node->left) {
            if(node->left->val==val+1) {
                longestConsecutiveHelper(node->left, currLen+1, res);
            }else {
                longestConsecutiveHelper(node->left, 1, res);
            }
        }if(node->right) {
            if(node->right->val==val+1) {
                longestConsecutiveHelper(node->right, currLen+1, res);
            }else {
                longestConsecutiveHelper(node->right, 1, res);
            }
        }

    }
    int longestConsecutive(TreeNode* root) {
        int res=1;

        longestConsecutiveHelper(root, 1, res);

        return res;
    }
};