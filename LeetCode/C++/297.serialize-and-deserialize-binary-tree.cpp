/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start
/** 
 * Accept: runtime 97.06%
 *          memory 49.62%
 */
class Codec {
private:
    void serialize(TreeNode* node, ostream& out) {
        if (!node) {
            out << '\0' << 0;
            return;
        }
        char status = VALID | 
            (node->left  ? HAS_LEFT  : NIL) | 
            (node->right ? HAS_RIGHT : NIL);
        out << status << node->val;
        serialize(node->left, out);
        serialize(node->right, out);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(istream& in) {
        char status;
        int val;
        in >> status >> val;
        TreeNode * ret = nullptr;
        if (status) {
            ret = new TreeNode(val);
            if (status | HAS_LEFT)
                ret->left = deserialize(in);
            if (status | HAS_RIGHT)
                ret->right = deserialize(in);
        }
        return ret;
    }
    
    enum type {
        NIL = 0, VALID = 1, 
        HAS_LEFT = 2, HAS_RIGHT = 4
    };

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
        return deserialize(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

