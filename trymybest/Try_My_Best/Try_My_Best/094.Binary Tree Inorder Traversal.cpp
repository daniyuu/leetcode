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
#include <stack>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> s;
        TreeNode  *p = root;
        

        do{
            // if it is not null, push to stack
            // and go down the tree to left
            while (p != NULL) {
                s.push(p);
                p = p->left;
            }
            
            // if no left child
            // pop stack, process the node
            // then let p point to the right
            if (!s.empty()) {
                p = s.top();
                s.pop();
                
                res.push_back(p->val);
                
                p = p->right;
            }
            
        }while (!s.empty() || p != NULL);
        return res;
    }
};