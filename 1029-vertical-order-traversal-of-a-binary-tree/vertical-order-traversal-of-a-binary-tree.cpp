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
    void verticalTraversalHelper(TreeNode* node, map<int, map<int, vector<int>>>& columns, int currCol, int currRow){
        if(!node){
            return;
        }

        columns[currCol][currRow].push_back(node->val);

        verticalTraversalHelper(node->left, columns, currCol-1, currRow+1);

        verticalTraversalHelper(node->right, columns, currCol+1, currRow+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> columns;
        verticalTraversalHelper(root, columns, 0, 0);
        vector<vector<int>> ans;

        for(auto& i1: columns){
            vector<int> colVals;

            for(auto& i2: i1.second){
                sort(i2.second.begin(), i2.second.end());
                colVals.insert(colVals.end(), i2.second.begin(), i2.second.end());
            }
            ans.push_back(colVals);

        }    

        return ans;
    }
};