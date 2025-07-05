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
    int isBalancedHelper(TreeNode* root, bool& soFar){
        if(!root){
            return 0;
        }

        int left=isBalancedHelper(root->left, soFar);
        int right=isBalancedHelper(root->right, soFar);
    
        if(!(left-right>=-1 && left-right<=1)){
            soFar=false;
        }

        return 1+max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        bool soFar=true;
        int temp=isBalancedHelper(root, soFar);
    
        return soFar;
    }
};