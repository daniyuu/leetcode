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
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

/* 方法二：根据bst的性质递归查找 */
//class Solution {
//public:
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        if (root->val == p->val || root->val == q->val) {
//            return root;
//        }
//        
//        if (p->val < root->val && root->val < q->val) {
//            return root;
//        }
//        
//        if (p->val > root->val && q->val > root->val) {
//            return lowestCommonAncestor(root->right, p, q);
//        }
//        if (p->val < root->val && q->val < root->val) {
//            return lowestCommonAncestor(root->left, p, q);
//        }
//        
//        return root;
//    }
//};

/* Better 方法一：找到两个节点的路径，然后根据路径找LCA。[followup] */

class Solution{
private:
    void getPath(TreeNode *root, TreeNode *p, vector<TreeNode *> &path){
        TreeNode *tmp = root;
        while (tmp != p) {
            path.push_back(tmp);
            if (tmp->val > p->val) {
                tmp = tmp->left;
            }else{
                tmp = tmp->right;
            }
        }
        
        path.push_back(p);
    }
public:
    TreeNode * lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q){
        vector<TreeNode *> path1, path2;
        getPath(root, p, path1);
        getPath(root, q, path2);
        TreeNode *res = root;
        int idx = 0;
        while (idx < path1.size() && idx < path2.size()) {
            if (path1[idx] != path2[idx]) {
                break;
            }else{
                res = path1[idx++];
            }
        }
        
        return res;
    }
};
