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
    void pushLeft(TreeNode*& node, stack<TreeNode*>& st) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> s1, s2;
        vector<int> res;

        pushLeft(root1, s1);
        pushLeft(root2, s2);

        while (!s1.empty() || !s2.empty()) {            
            if((s2.empty() || (!s1.empty() && s1.top()->val <= s2.top()->val))){
                TreeNode* node = s1.top(); s1.pop();
                res.push_back(node->val);
                pushLeft(node->right, s1);
            }else {
                TreeNode* node = s2.top(); s2.pop();
                res.push_back(node->val);
                pushLeft(node->right, s2);
            }
        }
        return res;
    }
};
