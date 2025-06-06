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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(!root){
            return ans;
        }

        queue<TreeNode*> helper;

        helper.push(root);


        while(!helper.empty()){
            vector<int> currLevel;
            int n=helper.size();
            for(int i=0; i<n; i++){
                TreeNode* curr=helper.front();
                helper.pop();
                currLevel.push_back(curr->val);
                if(curr->left){
                    helper.push(curr->left);
                }
                if(curr->right){
                    helper.push(curr->right);
                }
            }

            ans.push_back(currLevel);
        }

        return ans;
    }
};