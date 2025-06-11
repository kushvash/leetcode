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
    void goodNodesHelper(TreeNode* node, int maxV, int& count) {
        if(!node){
            return;
        }

        if(node->val>=maxV){
            maxV=node->val;
            count++;
        }

        goodNodesHelper(node->left, maxV, count);
        goodNodesHelper(node->right, maxV, count);
    }

    int goodNodes(TreeNode* root) {
        int count=0;
        goodNodesHelper(root, root->val, count);

        return count;
    }
};