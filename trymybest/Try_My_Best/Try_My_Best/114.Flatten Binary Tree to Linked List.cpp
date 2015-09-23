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
public:
    void flatten(TreeNode* root) {
        flatten(root, NULL);
    }
    
    TreeNode *flatten(TreeNode *root, TreeNode *tail){
        if (!root) {
            return tail;
        }
        
        root->right = flatten(root->left, flatten(root->right, tail));
        root->left = NULL;
        return root;
    }
};