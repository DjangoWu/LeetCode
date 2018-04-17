/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> st;
    
public:
    BSTIterator(TreeNode *root) {
        if (!root)
            return;
        while (root){
            st.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* tmp = st.top();
        int val = tmp->val;
        st.pop();
        if (tmp->right){
            tmp = tmp->right;
            while(tmp){
                st.push(tmp);
                tmp = tmp->left;
            }
        }
        return val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */