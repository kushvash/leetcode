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
    TreeNode* buildTreeHelper(vector<int>& postorder, int start, int end, unordered_map<int, int>& record, int& postIndex) {
        if(start>end || postIndex<0){
            return nullptr;
        }

        TreeNode* curr=new TreeNode(postorder[postIndex]);
        int mid=record[postorder[postIndex]];
        postIndex--;

        curr->right=buildTreeHelper(postorder, mid+1, end, record, postIndex); 
        curr->left=buildTreeHelper(postorder, start, mid-1, record, postIndex);

        return curr;
    }

    

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> record;
        int postIndex=inorder.size()-1;
        for(int i=0; i<inorder.size(); i++){
            record[inorder[i]]=i;
        }
        return buildTreeHelper(postorder, 0, postorder.size()-1, record, postIndex);
    }

};