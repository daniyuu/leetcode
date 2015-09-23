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
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    bool isSymmetric(TreeNode *left, TreeNode * right){
        if (!left && !right) {
            return true;
        }
        if (!left || !right) {
            return false;
        }
        
        return left->val == right->val
        && isSymmetric(left->left, right->right)
        && isSymmetric(left->right, right->left);
        
    }
public:
    bool isSymmetric(TreeNode* root) {
        return root ? isSymmetric(root->left, root->right): true;
    }
};