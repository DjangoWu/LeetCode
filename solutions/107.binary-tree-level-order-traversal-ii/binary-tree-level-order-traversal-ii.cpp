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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        if(root != NULL){
            q.push(root);
        }
        
        vector<int> levels;
        vector<vector<int>> res;
        
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
            res.push_back(levels);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};