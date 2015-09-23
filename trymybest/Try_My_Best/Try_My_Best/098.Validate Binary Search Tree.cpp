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

#include <iostream>
using namespace std;

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, (long long)INT_MIN - 1, (long long)INT_MAX + 1);
    }
private:
    bool isValidBST(TreeNode *root, long long lower, long long upper){
        if (root == nullptr) {
            return true;
        }
        
        return root->val > lower
        && root->val < upper
        && isValidBST(root->left, lower, root->val)
        && isValidBST(root->right,root->val, upper);
    }
};