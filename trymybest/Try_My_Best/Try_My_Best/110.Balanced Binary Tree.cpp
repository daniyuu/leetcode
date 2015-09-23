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
    bool isBalanced(TreeNode* root) {
        return getHeight(root) >= 0;
    }
    
private:
    int getHeight(TreeNode *root){
        if (!root) {
            return 0;
        }
        
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        
        if (left < 0 || right < 0 || abs(left - right) > 1) {
            return -1;
        }
        
        return max(left, right) + 1;
        
    }
};