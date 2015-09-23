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
    int minDepth(TreeNode *root, bool hasbrother){
        if (root == nullptr) {
            return hasbrother? INT_MAX:0;
        }
        
        return 1 + min(minDepth(root->left, root->right), minDepth(root->right, root->left));
        
        
    }
public:
    int minDepth(TreeNode* root) {
        return minDepth(root, false);
    }
};