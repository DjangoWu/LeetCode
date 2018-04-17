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
    
private:
    int leftSum = 0;
    
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root)
            return 0;
        DFS(root, false);
        return leftSum;
    }
    
    void DFS(TreeNode* node, bool isLeft){
        if (!node)
            return;
        if (node->left)
            DFS(node->left, true);
        if (node->right)
            DFS(node->right, false);
        if (!(node->left) && !(node->right) && isLeft)
            leftSum += node->val;
        
            
    
    }
};