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
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if(!root) {
            return {};
        }
        q.push(root);
        bool rev=false;

        while(!q.empty()) {
            int n=q.size();
            vector<int> temp;

            for(int i=0; i<n; i++) {
                TreeNode* tempNode=q.front();
                q.pop();

                temp.push_back(tempNode->val);
                
                if(tempNode->left) {
                    q.push(tempNode->left);
                }
                if(tempNode->right) {
                    q.push(tempNode->right);
                }
            }

            if(rev) {
                reverse(temp.begin(), temp.end());
                res.push_back(temp);
                rev=false;
            }else {
                res.push_back(temp);
                rev=true;
            }
        }

        return res;
    }
};