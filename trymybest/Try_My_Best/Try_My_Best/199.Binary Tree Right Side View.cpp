#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL),right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode *> pre;
        vector<int> res;
        
        if (!root) {
            return res;
        }
        
        pre.push(root);
        
        while (!pre.empty()) {
            res.push_back(pre.front()->val);
            queue<TreeNode *> cur;
            while (!pre.empty()) {
                if (pre.front()->right) {
                    cur.push(pre.front()->right);
                }
                if (pre.front()->left) {
                    cur.push(pre.front()->left);
                }
                pre.pop();
            }
            swap(pre, cur);
        }
        
        return res;
    }
};