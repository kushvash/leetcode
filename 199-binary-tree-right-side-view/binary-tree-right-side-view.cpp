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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> helper;

        if(!root){
            return {};
        }

        vector<int> ans;
        helper.push(root);

        while(!helper.empty()){
            int n=helper.size();
            vector<int> tempArr;

            for(int i=0; i<n; i++){
                TreeNode* temp=helper.front();
                helper.pop();
                tempArr.push_back(temp->val);

                if(temp->left){
                    helper.push(temp->left);
                }
                if(temp->right){
                    helper.push(temp->right);
                }
            }

            ans.push_back(tempArr[n-1]);
        }

        return ans;
    }
};