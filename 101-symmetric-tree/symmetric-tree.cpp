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
    bool isSymmetricHelper(vector<TreeNode*> level){
        int left=0, right=level.size()-1;

        while(left<right){
            if((!level[left] && level[right]) || (level[left] && !level[right])){
                return false;
            } 

            if((level[left] && level[right]) && level[left]->val != level[right]->val){
                return false;
            }

            left++;
            right--;
        } 

        return true;
    }

    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n=q.size();
            vector<TreeNode*> currLevel;

            for(int i=0; i<n; i++){
                TreeNode* temp = q.front();
                q.pop();
                currLevel.push_back(temp);

                if(!temp){
                    continue;
                }

                q.push(temp->left);
                q.push(temp->right);
            }

            if(!isSymmetricHelper(currLevel)){
                return false;
            }
        }

        return true;
    }
};