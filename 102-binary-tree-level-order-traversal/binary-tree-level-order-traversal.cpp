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
        vector<vector<int>> res;

        if(!root) {
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        int p=0;

        while(!q.empty()) {
            int n=q.size();
            res.push_back({});

            for(int i=0; i<n; i++) {
                TreeNode* temp=q.front();
                q.pop();
                res[p].push_back(temp->val);
                if(temp->left) {
                    q.push(temp->left);
                }
                if(temp->right) {
                    q.push(temp->right);
                }
            }
            p++;
        }

        return res;
    }
};