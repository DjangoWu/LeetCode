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
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        TreeNode* nl = root->left;
        TreeNode* nr = root->right;
        if (!nl && !nr)
            return true;
        else if (!nl || !nr)
            return false;
        queue<TreeNode*> Q1;
        queue<TreeNode*> Q2;
        Q1.push(nl);
        Q2.push(nr);
        while (!Q1.empty() && !Q2.empty()) {
            TreeNode* tmp1 = Q1.front();
            TreeNode* tmp2 = Q2.front();
            Q1.pop();
            Q2.pop();
            if ((!tmp1&&tmp2) || (tmp1&&!tmp2))
                return false;
            else if (tmp1 && tmp2){
                if (tmp1->val != tmp2->val)
                    return false;
                Q1.push(tmp1->left);
                Q1.push(tmp1->right);
                Q2.push(tmp2->right);
                Q2.push(tmp2->left);
            }
        }
        return true;
            
        
    }
};