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
    bool existPathSum = false;
    
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root)
            return false;
        DFS(root, 0, sum);
        return existPathSum;
    }
    
    void DFS(TreeNode* node, int pathSum, int sum){
        if (!node)
            return;
        pathSum += node->val;
        if (node->left){
            DFS(node->left, pathSum, sum);
        }
        if (node->right){
            DFS(node->right, pathSum, sum);
        }
        if (!(node->left) && !(node->right) && (pathSum == sum))
            existPathSum = true;
        
          
    }
    


    
};