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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        traverse(root, 1, res,true);
        return res;
    }
    
private:
    void traverse(TreeNode *root, int level, vector<vector<int>> &res, bool left_to_right){
        if (!root) {
            return;
        }
        
        if (level > res.size()) {
            res.push_back(vector<int>());
        }
        
        
        
        if (left_to_right) {
            res[level - 1].push_back(root->val);
        }else{
            res[level - 1].insert(res[level - 1].begin(), root->val);
        }
        
        traverse(root->left, level + 1, res, !left_to_right);
        traverse(root->right, level + 1, res, !left_to_right);
        
    }
};