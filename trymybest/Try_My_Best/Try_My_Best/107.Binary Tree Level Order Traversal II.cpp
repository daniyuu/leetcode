#include <iostream>
#include <vector>
#include <queue>
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

//class Solution {
//public:
//    vector<vector<int>> levelOrder(TreeNode* root) {
//        vector<vector<int>> res;
//        traverse(root, 1, res);
//        reverse(res.begin(), res.end());
//        return res;
//        
//    }
//private:
//    void traverse(TreeNode *root, size_t level, vector<vector<int>> &res){
//        if (!root) {
//            return;
//        }
//        
//        if (level > res.size()) {
//            res.push_back(vector<int>());
//        }
//        
//        res[level - 1].push_back(root->val);
//        traverse(root->left, level + 1, res);
//        traverse(root->right, level + 1, res);
//    }
//};

//class Solution {
//public:
//    vector<vector<int>> levelOrderBottom(TreeNode* root) {
//        vector<vector<int>> res;
//        traverse(root, 1, res);
//        return res;
//        
//    }
//private:
//    void traverse(TreeNode *root, size_t level, vector<vector<int>> &res){
//        if (!root) {
//            return;
//        }
//        
//        if (level > res.size()) {
//            res.insert(res.begin(), vector<int>());
//        }
//        
//        res[res.size() - level].push_back(root->val);
//        traverse(root->left, level + 1, res);
//        traverse(root->right, level + 1, res);
//    }
//};

/* BFS is better than DFS
 * reverse is better than insert
 */

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        q.push(root);
        int level = -1;
        
        while (!q.empty()) {
            level++;
            int sz = q.size();
            res.push_back(vector<int> ());
            
            for (int i = 0; i < sz; ++i) {
                TreeNode* top = q.front();
                res[level].push_back(top->val);
                q.pop();
                if (top->left != NULL) {
                    q.push(top->left);
                }
                if (top->right != NULL) {
                    q.push(top->right);
                }
            }
            
        }
        reverse(res.begin(), res.end());
        return res;
    }
};










