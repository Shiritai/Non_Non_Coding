/*
 * @lc app=leetcode id=449 lang=cpp
 *
 * [449] Serialize and Deserialize BST
 */

#include <climits>
#include <string>
#include <sstream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

// @lc code=start
/** 
 * Accept: runtime 92.26%
 *          memory 66.69%
 */
class Codec {
private:
    void serialize(TreeNode* node, ostringstream& out) {
        if (!node) 
            return;
        out.write(reinterpret_cast<char*>(&node->val), sizeof(int));
        serialize(node->left, out);
        serialize(node->right, out);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(istringstream& in, int l, int r) {
        int val;
        TreeNode * ret = nullptr;
        
        if (in.good()) {
            in.read(reinterpret_cast<char*>(&val), sizeof(int));
            if (val > l && val < r) { // in range
                ret = new TreeNode(val);
                ret->left = deserialize(in, l, val);
                ret->right = deserialize(in, val, r);
            }
            else 
                in.seekg(-sizeof(int)/sizeof(char), ios::cur);
        }
        return ret;
    }
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return data.empty() ? nullptr : deserialize(in, INT_MIN, INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end

