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
    void verticalTraversalHelper(TreeNode* root, int row, int col, map<int, map<int, vector<int>>>& res) {
        if(!root){
            return;
        }
        
        res[col][row].push_back(root->val);

        verticalTraversalHelper(root->left, row+1, col-1, res);
        verticalTraversalHelper(root->right, row+1, col+1, res);

        return;
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> res;

        verticalTraversalHelper(root, 0, 0, res);

        vector<vector<int>> ans;

        for (auto& [col, rows] : res) {
            vector<int> colVals;
            for (auto& [row, vals] : rows) {
                sort(vals.begin(), vals.end());
                colVals.insert(colVals.end(), vals.begin(), vals.end());
            }
            ans.push_back(move(colVals));
        }
        return ans;

    }
};