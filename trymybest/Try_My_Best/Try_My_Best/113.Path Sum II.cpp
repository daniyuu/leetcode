#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class Solution{
private:
    void dfs(TreeNode *root, int rest, vector<int> &path, vector<vector<int>> &res){
        if (root == NULL) {
            return;
        }
        path.push_back(root->val);
        rest -= root->val;
        
        if (!root->left && !root->right) {
            if (rest == 0) {
                res.push_back(path);
            }
        }else{
            if (root->left) {
                dfs(root->left, rest, path, res);
            }
            if (root->right) {
                dfs(root->right, rest, path, res);
            }
        }
        
        
        path.pop_back();
        
    }
public:
    vector<vector<int>> pathSum(TreeNode *root, int sum){
        vector<vector<int>> res;
        vector<int> path;
        
        return res;
    }
};