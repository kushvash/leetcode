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
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root){
            return {0};
        }

        vector<double> ans;
        queue<TreeNode*> helper;
        helper.push(root);

        while(!helper.empty()){
            int n=helper.size();
            double curr=0;
            for(int i=0; i<n; i++){
                TreeNode* top=helper.front();
                curr+=top->val;
                helper.pop();

                if(top->left){
                    helper.push(top->left);
                }
                if(top->right){
                    helper.push(top->right);
                }
            }

            ans.push_back(curr/n);
        }

        return ans;
    }
};