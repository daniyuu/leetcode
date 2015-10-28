/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void inorder(TreeNode *root){
        if (root->left) {
            inorder(root->left);
        }
        if (pre != NULL && (root->val < pre->val)) {
            if (mistake1 == NULL) {
                mistake1 = pre;
            }
            mistake2 = root;
        }
        pre = root;
        if (root->right) {
            inorder(root->right);
        }
        
    }
public:
    TreeNode *mistake1, *mistake2;
    TreeNode *pre;
    void recoverTree(TreeNode* root) {
        mistake1 = mistake2 = pre = NULL;
        inorder(root);
        swap(mistake1->val, mistake2->val);
        
        return;
    }
};