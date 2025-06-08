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
    void kthSmallestHelper(TreeNode* node, int& count, int& ans){
        if(count==0 || !node){
            return;
        }

        kthSmallestHelper(node->left, count, ans);
        count--;
        if(count==0){
            ans=node->val;
            return;
        }
        kthSmallestHelper(node->right, count, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans=0;
        kthSmallestHelper(root, k, ans);
        return ans;
    }
};