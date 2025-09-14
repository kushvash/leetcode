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
    bool isSameTree(TreeNode* node1, TreeNode* node2) {
        if(node1 && !node2) {
            return false;
        }
        if(!node1 && node2) {
            return false;
        }
        if(!node1 && !node2) {
            return true;
        }

        if(node1->val==node2->val) {
            return isSameTree(node1->left, node2->left) && isSameTree(node1->right, node2->right);
        }
        
        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {
            TreeNode* temp=q.front();
            q.pop();
            if(temp->val==subRoot->val) {
                if(isSameTree(temp, subRoot)) {
                    return true;
                }
            }
            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }

        return false;
    }
};