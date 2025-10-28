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
    int kthSmallest(TreeNode* root, int k) {
        int i=0;
        stack<TreeNode*> st;
        TreeNode* node=root;
        st.push(root);

        while(true) {
            if(node!=NULL) {
                st.push(node);
                node=node->left;
            }else {
                if(st.empty()) {
                    break;
                }
                node=st.top();
                st.pop();
                i++;
                if(i==k) {
                    return node->val;
                }
                node=node->right;
            }
        }

        return -1;
    }
};