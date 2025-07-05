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
    void kthSmallestHelper(TreeNode* root, int k, vector<int>& arr){
        if(arr.size()==k || !root){
            return;
        }

        kthSmallestHelper(root->left, k, arr);

        arr.push_back(root->val);

        kthSmallestHelper(root->right, k, arr);

        return;
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;

        kthSmallestHelper(root, k, arr);
    
        return arr[k-1];
    }
};