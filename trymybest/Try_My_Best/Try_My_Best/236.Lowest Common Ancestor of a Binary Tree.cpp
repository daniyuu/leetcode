/**
 *
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
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

/* 根据路径找LCA。 */
class Solution {
private:
    void getPath(TreeNode *root, TreeNode *p, vector<TreeNode *> &path, vector<TreeNode *> &res){
        if (root == NULL) {
            return;
        }
        
        path.push_back(root);
        
        // 不需要考虑那么多 给定的点包含状态 只用直接对比就行
        if (root == p) {
            res = path;
        }
        
        getPath(root->left, p, path,res);
        getPath(root->right, p, path,res);
        
        path.pop_back();
        
    }
public:
    void print(vector<TreeNode *> path){
        for (int i = 0; i < path.size(); ++i) {
            cout << path[i]->val << " ";
        }
        cout << endl;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        vector<TreeNode *> temp1, temp2;
        vector<TreeNode *> p1, p2;
        getPath(root, p, temp1, p1);
        getPath(root, q, temp2, p2);

        

        TreeNode *res = root;
        int idx = 0;
        while (idx < p1.size() && idx < p2.size()) {
            if (p1[idx] != p2[idx]) {
                break;
            }else{
                res = p1[idx];
                idx++;
            }
        }
                

        return res;
    }
};

//int main(){
//    TreeNode *root = new TreeNode(-1);
//    TreeNode *t1 = new TreeNode(-100);
//    TreeNode *t2 = new TreeNode(-100);
//    TreeNode *t3 = new TreeNode(-2);
//    TreeNode *t4 = new TreeNode(4);
//    TreeNode *t5 = new TreeNode(8);
//    
//    t3->left = t5;
//    
//    t1->left = t3;
//    t1->right = t4;
//    
//    root->left = t1;
//    root->right = t2;
//    
//    TreeNode *p = new TreeNode(-2);
//    TreeNode *q = new TreeNode(8);
//    
//    Solution s;
//    cout << s.lowestCommonAncestor(root, p, q)->val;
//}