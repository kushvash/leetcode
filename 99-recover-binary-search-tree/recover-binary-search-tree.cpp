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
    TreeNode *first = nullptr,
             *second = nullptr,
             *prev = nullptr;
public:
    void recoverTreeHelper(TreeNode* node){
        if(!node){
            return;
        }
        recoverTreeHelper(node->left);

        if(prev && prev->val>node->val){
            if(!first){
                first=prev;
            }
            second=node;
        }

        prev=node;
        recoverTreeHelper(node->right);
    }

    void recoverTree(TreeNode* root) {
        recoverTreeHelper(root);

        if(first && second){
            swap(first->val, second->val);
        }    
    }
};