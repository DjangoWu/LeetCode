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
    int sum;
    
    int sumNumbers(TreeNode* root) {
        sum = 0;
        if(root == NULL)
            sum = 0;
        else 
            count(root, 0);
        return sum;
    }
    
    void count(TreeNode* node, int num){
        num *= 10;
        num += node->val;
        if(node->left == NULL && node->right == NULL){
            sum += num;
        }
        if(node->left != NULL)
            count(node->left, num);
        if(node->right != NULL)
            count(node->right, num);
    }
};