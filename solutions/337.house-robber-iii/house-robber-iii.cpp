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
    int rob(TreeNode* root) {
        if (!root)
            return 0;
        vector<int> temp = DFS(root);
        return max(temp[0], temp[1]);
    }
    
    vector<int> DFS(TreeNode* node){
        vector<int> res(2, 0);
        if (!node)
            return res;
        if (node->left){
            vector<int> temp;
            temp = DFS(node->left);
            res[0] += max(temp[0], temp[1]);
            res[1] += temp[0];
        }
        if (node->right){
            vector<int> temp;
            temp = DFS(node->right);
            res[0] += max(temp[0], temp[1]);
            res[1] += temp[0];
        }
        res[1] += node->val;
        return res;
    }
};