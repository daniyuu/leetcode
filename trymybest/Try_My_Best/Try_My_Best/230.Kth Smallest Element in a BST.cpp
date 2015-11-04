#include <iostream>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

//class Solution {
//private:
//    int calcTreeSize(TreeNode *root){
//        if (root == NULL) {
//            return 0;
//        }
//        return 1 + calcTreeSize(root->left) + calcTreeSize(root->right);
//    }
//public:
//    int kthSmallest(TreeNode* root, int k) {
//        if (root == NULL) {
//            return 0;
//        }
//        
//        int leftSize = calcTreeSize(root->left);
//        
//        if (k == leftSize + 1) {
//            return root->val;
//        }else if (leftSize >= k){
//            return kthSmallest(root->left, k);
//        }else{
//            return kthSmallest(root->right, k - leftSize - 1);
//        }
//    }
//};
class Solution {
public:
    int kthSmallest(TreeNode *root, int k){
        int num = 0;
        int result = 0;
        visit(root, k, num,result);
        
        return result;
    }
    
private:
    bool flag = false; // prune
    void visit(TreeNode *root, int k, int &num, int &result){
        if (flag) {
            return;
        }
        if (!root) {
            return;
        }
        visit(root->left, k, num, result);
        if (num < k) {
            num += 1;
            if (num == k) {
                result = root->val;
                flag = true;
                return;
            }
        }
        visit(root->right, k, num, result);
    }
};