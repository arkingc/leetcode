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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "#";
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return deserializeCore(data);
    }
    
private:
    TreeNode* deserializeCore(string &data){
        if(data == "")    return NULL;
        
        if(data[0] == '#'){
            data = data.substr(data.find(',') + 1);
            return NULL;
        }
        
        size_t idx;
        int val = stoi(data,&idx);
        data = data.substr(idx + 1);
        
        TreeNode *node = new TreeNode(val);
        
        node->left = deserializeCore(data);
        node->right = deserializeCore(data);
        
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));