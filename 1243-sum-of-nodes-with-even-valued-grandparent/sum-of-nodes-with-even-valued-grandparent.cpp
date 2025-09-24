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
    int sumEvenGrandparent(TreeNode* root) {
        queue<pair<TreeNode*, vector<int>>> q;
        int res=0;

        q.push({root, {-1, -1}});

        while(!q.empty()) {
            auto tempPair=q.front();
            int tempVal=tempPair.first->val;
            int tempParent=tempPair.second[0];
            int tempGParent=tempPair.second[1];
            q.pop();
            if(tempGParent%2==0) {
                res+=tempVal;
            }

            if(tempPair.first->left) {
                q.push({tempPair.first->left, {tempVal, tempParent}});
            }
            if(tempPair.first->right) {
                q.push({tempPair.first->right, {tempVal, tempParent}});
            }
        }

        return res;
    }
};