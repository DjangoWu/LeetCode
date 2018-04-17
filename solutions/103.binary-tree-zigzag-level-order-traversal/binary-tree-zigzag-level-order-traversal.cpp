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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if(root != NULL){
            q.push(root);
        }
        
        vector<int> levels;
        vector<vector<int>> res;
        bool odd = true;
        while(!q.empty()){
            int size = q.size();
            levels.clear();
            while(size--){
                TreeNode* temp = q.front();
                q.pop();
                levels.push_back(temp->val);
                if(temp->left != NULL)
                    q.push(temp->left);
                if(temp->right != NULL)
                    q.push(temp->right);
            }
            if (odd) {
                res.push_back(levels);
                odd = false;
            }
                
            else {
                reverse(levels.begin(), levels.end());
                res.push_back(levels);
                odd = true;
            }
        }
        return res;
    }
};