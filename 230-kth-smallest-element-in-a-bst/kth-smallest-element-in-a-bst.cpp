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
    void kthSmallestHelper(TreeNode* node, int k, int& i, int& ans){
        if(!node || ans!=-1){
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


    int kthSmallest(TreeNode* root, int k){
        int i=0;
        int ans=-1;
        kthSmallestHelper(root, k, i, ans);

        return ans;
    }
};