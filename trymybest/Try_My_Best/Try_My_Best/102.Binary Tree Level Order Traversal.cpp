#include <iostream>
#include <vector>

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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        traverse(root, 1, res);
        return res;
        
    }
private:
    void traverse(TreeNode *root, size_t level, vector<vector<int>> &res){
        if (!root) {
            return;
        }
        
        if (level > res.size()) {
            res.push_back(vector<int>());
        }
        
        res[level - 1].push_back(root->val);
        traverse(root->left, level + 1, res);
        traverse(root->right, level + 1, res);
    }
};