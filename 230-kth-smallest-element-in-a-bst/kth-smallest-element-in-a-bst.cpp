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
    void kthSmallestHelper(TreeNode* node, int& k, vector<int>& arr){
        if(arr.size()==k || !node){
            return;
        }

        kthSmallestHelper(node->left, k, arr);
        if(arr.size()<k){
            arr.push_back(node->val);
        }else{
            return;
        }
        kthSmallestHelper(node->right, k, arr);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        kthSmallestHelper(root, k, arr);
        return arr[arr.size()-1];
    }
};