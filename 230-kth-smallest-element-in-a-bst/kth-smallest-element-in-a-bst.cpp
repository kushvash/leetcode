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
    void kthSmallestHelper(TreeNode* node, int k, int& i, int& ans) {
        if(!node){
            return;
        }
        if(i>k){
            return;
        }

        kthSmallestHelper(node->left, k, i, ans);

        i++;
        if(i==k){
            ans=node->val;
            return;
        }

        kthSmallestHelper(node->right, k, i, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=0, i=0;

        kthSmallestHelper(root, k, i, ans);

        return ans;
    }
};