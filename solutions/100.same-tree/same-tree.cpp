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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;
        else if (!p || !q)
            return false;
        
        bool cond1 = (p->val == q->val);
        bool cond2 = isSameTree(p->left, q->left);
        bool cond3 = isSameTree(p->right, q->right);
        return cond1 && cond2 && cond3;
    }
};