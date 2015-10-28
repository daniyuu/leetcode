/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
 [思路]
 用暴力法, recursive求会超时 O(N).   
 如果从某节点一直向左的高度 = 一直向右的高度, 那么以该节点为root的子树一定是complete binary tree. 
 而 complete binary tree的节点数,可以用公式算出 2^h - 1. 如果高度不相等, 则递归调用 return countNode(left) + countNode(right) + 1.  复杂度为O(h^2)

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
    int getLeft(TreeNode *root){
        int count = 0;
        if (root == NULL) {
            return 0;
        }
        while (root->left != NULL) {
            root = root->left;
            ++count;
        }
        return count;
    }
    
    int getRight(TreeNode *root){
        int count = 0;
        if (root == NULL) {
            return 0;
        }
        
        while (root->right != NULL) {
            root = root->right;
            ++count;
        }
        
        return count;
    }
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        int l = getLeft(root) + 1;
        int r = getRight(root) + 1;
        
        if (l == r) {
            return (2 << (l  - 1)) - 1;
        }else{
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
        
    }
};