#include <iostream>
#include <queue>
using namespace std;

struct TreeLinkNode{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x):val(x), left(NULL), right(NULL), next(NULL){}
    
};
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode *> q;
        if (root == NULL) {
            return;
        }
        
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            TreeLinkNode *pre = q.front();
            TreeLinkNode *next = q.front();
            for (int i = 0; i < sz - 1; ++i) {
                pre = q.front();
                q.pop();
                next = q.front();
                pre->next = next;
                if (pre->left != NULL) {
                    q.push(pre->left);
                }
                if (pre->right != NULL) {
                    q.push(pre->right);
                }
            }
            if (pre == next) {
                next->next = NULL;
                q.pop();
            }else{
                pre = next;
                next = q.front();
                q.pop();
                pre->next = next;
                next->next = NULL;
            }
            
            if (next->left != NULL) {
                q.push(next->left);
            }
            if (next->right != NULL) {
                q.push(next->right);
            }
        
        }
        
    }
};