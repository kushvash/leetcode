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
    void sumNumbersHelper(TreeNode* node, int currNum, int& sum){
        currNum*=10;
        currNum+=node->val;

        if(!node->left && !node->right){
            sum+=currNum;
            return;
        }

        if(node->left){
            sumNumbersHelper(node->left, currNum, sum);
        }
        if(node->right){
            sumNumbersHelper(node->right, currNum, sum);
        }

        return;
    }

    int sumNumbers(TreeNode* root) {
        int sum=0;

        sumNumbersHelper(root, 0, sum);

        return sum;
    }
};