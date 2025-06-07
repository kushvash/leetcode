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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            vector<int> tempArr;
            int n=q.size();

            TreeNode* parentX=nullptr;
            TreeNode* parentY=nullptr;

            for(int i=0; i<n; i++){
                TreeNode* temp=q.front();
                q.pop();

                if(temp->left){
                    if(temp->left->val==x){
                        parentX=temp;
                    }else if(temp->left->val==y){
                        parentY=temp;
                    }
                    q.push(temp->left);
                }
                if(temp->right){
                    if(temp->right->val==x){
                        parentX=temp;
                    }else if(temp->right->val==y){
                        parentY=temp;
                    }
                    q.push(temp->right);
                }
            }

            if(parentX && parentY){
                return parentX != parentY;
            }else if(parentX || parentY){
                return false;;
            }
        }

        return false;
    }
};