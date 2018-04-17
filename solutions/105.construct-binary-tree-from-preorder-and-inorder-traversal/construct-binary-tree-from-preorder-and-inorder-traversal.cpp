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
    unordered_map<int, int> m;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() <= 0)
            return NULL;
        for (int i = 0; i < inorder.size(); ++i)
            m[inorder[i]] = i;
        
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    
    TreeNode* build(vector<int>& preorder, int start1, int end1, vector<int>& inorder, int start2, int end2) {
        if (start1 > end1 || start2 > end2)
            return NULL;
        int mid = m[preorder[start1]];
        int num = mid - start2;
        TreeNode* root = new TreeNode(inorder[mid]);
        root->left = build(preorder, start1+1, start1+num, inorder, start2, mid-1);
        root->right = build(preorder, start1+num+1, end1, inorder, mid+1, end2);
        return root;
    }
};