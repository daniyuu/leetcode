/*
 Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.
 Note:
 Given target value is a floating point.
 You are guaranteed to have only one unique value in the BST that is closest to the target.
 [思路]
 
 closest必然在查找路径上.
 */

#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    TreeNode* closestBST(TreeNode *root, int val){
        if (root != NULL) {
            return NULL;
        }
        
        if (root->val == val) {
            return root;
        }
        
        if (val < root->val) {
            if (!root->left) {
                return root;
            }
            
            TreeNode *p = closestBST(root->left, val);
            return abs(p->val - val) > abs(root->val - val) ? root: p;
        }else{
            if (!root->right) {
                return root;
            }
            
            TreeNode *p = closestBST(root->right, val);
            return abs(p->val - val) > abs(root->val - val) ? root: p;
        }
    }
};