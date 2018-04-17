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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if (!root)
            return res;
        q.push(root);
        
        while (!q.empty()) {
            vector<int> level;
            int size = q.size();
            while(size--) {
                TreeNode* tmp = q.front();
                q.pop();
                level.push_back(tmp->val);
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
            }
            res.push_back(level);
        }
        return res;
    }
};