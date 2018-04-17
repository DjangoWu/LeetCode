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
    vector<vector<int>> ans;
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root)
            return ans;
        vector<int> tmp;
        DFS(root, tmp, 0, sum);
        return ans;
    }
    
    void DFS(TreeNode* node, vector<int>& tmp, int pathSum, int sum){
        if (!node)
            return;
        tmp.push_back(node->val);
        pathSum += node->val;
        if (node->left)
            DFS(node->left, tmp, pathSum, sum);
        if (node->right)
            DFS(node->right, tmp, pathSum, sum);
        
        if (!node->left && !node->right){
            if (pathSum == sum)
                ans.push_back(tmp);   
        }
        tmp.pop_back();
    }
};