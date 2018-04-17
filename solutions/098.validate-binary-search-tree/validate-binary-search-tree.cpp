/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return valid(root, (long)INT_MIN-1, (long)INT_MAX+1);
    }
    
    bool valid(TreeNode* node, long minVal, long maxVal) {
        if (!node)
            return true;
        if (node->val <= minVal || node->val >= maxVal)
            return false;
        return valid(node->left, minVal, node->val) && valid(node->right, node->val, maxVal);
    }
};