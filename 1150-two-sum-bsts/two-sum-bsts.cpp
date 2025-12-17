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
    void traverseBST(TreeNode* node, unordered_set<int>& st) {
        if(!node) {
            return;
        }

        st.insert(node->val);

        traverseBST(node->left, st);
        traverseBST(node->right, st);
    }

    bool findBST(TreeNode* node, unordered_set<int>& st, int target) {
        if(!node) {
            return false;
        }

        if(st.find(target-node->val)!=st.end()) {
            return true;
        }

        return (findBST(node->left, st, target) || findBST(node->right, st, target));
    }

    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        unordered_set<int> st;

        traverseBST(root1, st);

        return findBST(root2, st, target);
    }
};