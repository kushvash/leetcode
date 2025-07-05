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
    int goodNodesHelper(TreeNode* root, int currMax){
        if(!root){
            return 0;
        }

        int nextMax=max(currMax, root->val);
        int leftAns=goodNodesHelper(root->left, nextMax);
        int rightAns=goodNodesHelper(root->right, nextMax);

        if(root->val>=currMax){
            return (1+leftAns+rightAns);
        }

        return leftAns+rightAns;
    }

    int goodNodes(TreeNode* root) {
        return goodNodesHelper(root, INT_MIN);    
    }
};