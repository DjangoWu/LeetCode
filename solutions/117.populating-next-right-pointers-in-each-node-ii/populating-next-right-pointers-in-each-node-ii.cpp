/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
    
    queue<TreeLinkNode*> nodeQueue;
    int count;
    
public:
    void connect(TreeLinkNode *root) {
        if (!root)
            return;
        nodeQueue.push(root);
        count = 1;
        while (!nodeQueue.empty()) {
            int levelCount = 0;
            for (int i = 0; i < count; i++){
                TreeLinkNode* tmp = nodeQueue.front();
                nodeQueue.pop();
                if (i == count-1)
                    tmp->next = NULL;
                else
                    tmp->next = nodeQueue.front();
                
                if (tmp->left){
                    nodeQueue.push(tmp->left);
                    levelCount++;
                }
                if (tmp->right){
                    nodeQueue.push(tmp->right);
                    levelCount++;
                }
            }
            count = levelCount;
        }
        
    }
};