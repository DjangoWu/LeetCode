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
    vector<string> ans;
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root)
            return ans;
        else {
            string str = to_string(root->val);
            DFS(root, str);
            return ans;
        }
    }
    
    void DFS(TreeNode* node, string str) {
        string tmp = str;
        if (node->left) {
            tmp += "->";
            tmp += to_string(node->left->val);
            DFS(node->left, tmp);
        }
        if (node->right) {
            str += "->";
            str += to_string(node->right->val);
            DFS(node->right, str);
        }
        if (!node->left && !node->right)
            ans.push_back(str);
        
    }
};