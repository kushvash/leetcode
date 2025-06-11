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
    int isBalancedHelper(TreeNode* node, bool& record) {
        if(!node || !record){
            return 0;
        }

        int l=1+isBalancedHelper(node->left, record), r=1+isBalancedHelper(node->right, record);

        if(l-r>1 || l-r<-1){
            record=false;
            return 0;
        }

        return max(l, r);
    }

    bool isBalanced(TreeNode* root) {
        bool record=true; 

        isBalancedHelper(root, record);

        return record;   
    }
};