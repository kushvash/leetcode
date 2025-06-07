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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root){
            return {};
        }

        queue<TreeNode*> helper;
        vector<vector<int>> ans;
        helper.push(root);
        bool ifRev=false;

        while(!helper.empty()){
            int n=helper.size();
            vector<int> currLevel(n);

            for(int i=0; i<n; i++){
                TreeNode* temp=helper.front();
                helper.pop();

                if(ifRev){
                    currLevel[n-i-1]=temp->val;
                }else{
                    currLevel[i]=temp->val;
                }

                if(temp->left){
                    helper.push(temp->left);
                }
                if(temp->right){
                    helper.push(temp->right);
                }

            }    

            if(ifRev){
                ifRev=false;
            }else{
                ifRev=true;
            }

            ans.push_back(currLevel);
        }


        return ans;

    }
};