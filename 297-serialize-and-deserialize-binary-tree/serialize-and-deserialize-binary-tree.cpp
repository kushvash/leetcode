/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void serializeHelper(TreeNode* node, string& ans){
        if(!node){
            ans+="null,";
            return;
        }

        ans+=to_string(node->val)+",";
        serializeHelper(node->left, ans);
        serializeHelper(node->right, ans);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        serializeHelper(root, ans);
        return ans;
    }

    TreeNode* deserializeHelper(queue<string>& tokens) {
        string tok = tokens.front(); 
        tokens.pop();
        if (tok == "null"){
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(tok));
        node->left  = deserializeHelper(tokens);
        node->right = deserializeHelper(tokens);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> tokens;
        string token;
        
        for (char c : data) {
            if (c == ',') {
                tokens.push(token);
                token.clear();
            } else {
                token.push_back(c);
            }
        }
        if (!token.empty()) {
            tokens.push(token);
        }

        return deserializeHelper(tokens);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));