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
    bool kthSmallestHelper(TreeNode* node, int k, int& i, int& ans){
        if(!node){
            return false;
        }


        if(kthSmallestHelper(node->left, k, i, ans)){
            return true;
        }

        i++;
        if(i==k){
            ans=node->val;
            return true;
        }

        return kthSmallestHelper(node->right, k, i, ans);

    }


    int kthSmallest(TreeNode* root, int k){
        int i=0;
        int ans;
        if(kthSmallestHelper(root, k, i, ans)){
            return ans;
        }

        return ans;
    }
};