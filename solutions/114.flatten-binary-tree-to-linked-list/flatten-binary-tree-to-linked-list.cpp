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
    void flatten(TreeNode* root) {
        if (root == NULL)  
        {  
            return;  
        }  
          
        stack<TreeNode *> st;  
        st.push(root);  
        vector<TreeNode *> vt;  
          
        // 前序遍历  利用压栈出栈来控制
        while (!st.empty())  
        {  
            TreeNode * t = st.top();  
            st.pop();  
            vt.push_back(t);  
              
            if (t->right)  
            {  
               st.push(t->right);   
            }  
              
            if (t->left)  
            {  
                st.push(t->left);  
            }  
        }  
        
        // 连接节点
        for (int i = vt.size() - 1; i >= 0; --i)  
        {  
            if (i == vt.size() - 1)  
            {  
                vt[i]->right = NULL;  
                vt[i]->left = NULL;  
            }  
            else  
            {  
                vt[i]->right = vt[i + 1];  
                vt[i]->left = NULL;  
            }  
        }  
    }

};