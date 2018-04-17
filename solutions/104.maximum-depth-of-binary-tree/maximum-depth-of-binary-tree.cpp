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
    int depth = 0;
    
public:
    int maxDepth(TreeNode* root) {
        if (root){
            depth = 1; 
            DFS(root, 1);
        }
           
        return depth;
    }
    
    void DFS(TreeNode* node, int level){
        if (!node)
            return;
        //std::cout << node->val << " " << level << std::endl;
        if (node->left){
            if (level+1 > depth)
                depth = level+1;
            DFS(node->left, level+1);
        }
        if (node->right){
            if (level+1 > depth)
                depth = level+1;
            DFS(node->right, level+1);
        }
        
    }
};