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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if(!root) {
            return {};
        }

        q.push(root);
    
        while(!q.empty()) {
            int n=q.size();
            vector<int> currLevel;

            for(int i=0; i<n; i++) {
                TreeNode* currNode=q.front();
                q.pop();
                currLevel.push_back(currNode->val);

                if(currNode->left) {
                    q.push(currNode->left);
                }
                if(currNode->right) {
                    q.push(currNode->right);
                }
            }
            res.push_back(currLevel);
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};