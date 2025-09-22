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
    pair<int, int> helper(TreeNode* node, int& ans) {
        if(!node->left && !node->right) {
            ans++;
            return {node->val, 1};
        }

        int tempSum=node->val, tempNodes=1;

        if(node->left) {
            pair<int, int> temp=helper(node->left, ans);
            tempSum+=temp.first;
            tempNodes+=temp.second;
        }
        if(node->right) {
            pair<int, int> temp=helper(node->right, ans);
            tempSum+=temp.first;
            tempNodes+=temp.second;
        }

        if(node->val==(tempSum/tempNodes)) {
            ans++;
        }

        return {tempSum, tempNodes};
    }

    int averageOfSubtree(TreeNode* root) {
        int ans=0;

        helper(root, ans);

        return ans;
    }
};