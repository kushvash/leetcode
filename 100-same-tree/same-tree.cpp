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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If one is null but other is not
        if(p || q){
            if((!p) || (!q)){
                return false;
            }
        }
        // If both are null
        if(!(p && q)){
            return true;
        }

        // If the values are diff
        if(p->val!=q->val){
            return false;
        }

        // If values are same
        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};