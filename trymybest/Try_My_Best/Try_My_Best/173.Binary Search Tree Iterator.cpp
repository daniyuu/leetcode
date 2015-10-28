/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 
 
 解法二：空间复杂度O(h)的解法
 
 每次取出栈顶元素（即当前最小）后，查找下一个元素并压栈。
 */

#include <iostream>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL),right(NULL) {}
};

class BSTIterator {
private:
    stack<TreeNode *> stk;
    int nextmin;
public:
    BSTIterator(TreeNode *root) {
        while (root) {
            stk.push(root);
            root = root->left;
        }
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (!stk.empty()) {
            TreeNode *top = stk.top();
            stk.pop();
            // min item
            nextmin = top->val;
            
            // find next min push them
            TreeNode *cur = top->right;
            if (cur) {
                stk.push(cur);
                cur = cur->left;
                while (cur) {
                    stk.push(cur);
                    cur = cur->left;
                }
            }
            return true;
        }else{
            return false;
        }
        
    }
    
    /** @return the next smallest number */
    int next() {
        return nextmin;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */