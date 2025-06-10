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
    // Builds a subtree from inorder[start..end]
    TreeNode* buildTreeHelper(const vector<int>& preorder, int start, int end, const unordered_map<int,int>& inPos, int& preIdx) {
        // 1) No nodes in this range
        if (start > end) 
            return nullptr;

        // 2) Next preorder value is this subtree’s root
        int rootVal = preorder[preIdx];
        preIdx++;
        TreeNode* root = new TreeNode(rootVal);

        // 3) Find where rootVal sits in inorder
        int mid = inPos.at(rootVal);

        // 4) Recursively build left subtree from start..mid-1
        root->left = buildTreeHelper(preorder, start, mid - 1, inPos, preIdx);
        // 5) Recursively build right subtree from mid+1..end
        root->right = buildTreeHelper(preorder, mid + 1, end, inPos, preIdx);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        // Precompute each value’s index in inorder
        unordered_map<int,int> inPos;
        int preIdx=0;  // index into preorder

        // inPos.reserve(n);
        for (int i = 0; i < n; i++)
            inPos[inorder[i]] = i;

        // Build the entire tree from inorder[0..n-1]
        return buildTreeHelper(preorder, 0, n - 1, inPos, preIdx);
    }
};