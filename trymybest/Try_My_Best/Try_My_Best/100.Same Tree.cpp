/* BFS is better */

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};


class Solution {
private:
    bool testNode(TreeNode* root1, TreeNode *root2){
        
        if (root1->val != root2->val) {
            return false;
        }
        
        TreeNode *p_left = root1->left;
        TreeNode *q_left = root2->left;
        TreeNode *p_right = root1->right;
        TreeNode *q_right = root2->right;
        
        if (!p_left && !q_left && !p_right && !q_right) {
            return true;
        }
        
        if ( (p_left && !q_left) || (q_left && !p_left)) {
            return false;
        }
        
        if ( (p_right && !q_right) || (q_right && !p_right)) {
            return false;
        }
        
        return true;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        
        if (!p && !q) {
            return true;
        }
        
        if ( (p && !q) || (q && !p)) {
            return false;
        }
        
        q1.push(p);
        q2.push(q);
        
        while ((!q1.empty()) && (!q2.empty())) {
            int sz = q1.size();
            for (int i = 0; i < sz; ++i) {
                TreeNode* q1_top = q1.front();
                TreeNode* q2_top = q2.front();
                q1.pop();
                q2.pop();
                if (!testNode(q1_top, q2_top)) {
                    return false;
                }
                if (q1_top->left != NULL) {
                    q1.push(q1_top->left);
                    q2.push(q2_top->left);
                }
                
                if (q1_top->right != NULL) {
                    q1.push(q1_top->right);
                    q2.push(q2_top->right);
                }
                
            }
            
        }
        
        return true;
    }
};