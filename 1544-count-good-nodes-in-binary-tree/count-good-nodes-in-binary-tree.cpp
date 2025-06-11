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
    int goodNodesHelper(TreeNode* node, int maxV) {
        if(!node){
            return 0;
        }

        int count=0;
        if(node->val>=maxV){
            maxV=node->val;
            count++;
        }

        count+=goodNodesHelper(node->left, maxV);
        count+=goodNodesHelper(node->right, maxV);

        return count;
    }

    int goodNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        return goodNodesHelper(root, root->val);
    }
};