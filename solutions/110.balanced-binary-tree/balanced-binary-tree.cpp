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
    bool isBalanced(TreeNode* root) {
        // corner case check
        if (root == NULL)
            return true;
        int isBalanced = getHeight(root);
        if (isBalanced != -1)
            return true;
        else 
            return false;
    }
    
    int getHeight (TreeNode* root) {
        
        if (root == NULL)
            return 0;
        int leftHeight = getHeight(root->left);
        if (leftHeight == -1)
            return -1;
        int rightHeight = getHeight(root->right);
        if (rightHeight == -1)
            return -1;
        int diffHeight = max(rightHeight - leftHeight, leftHeight - rightHeight);
        if (diffHeight > 1)
            return -1;
        else
            return max(leftHeight, rightHeight) + 1;
    }
};