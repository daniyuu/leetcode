#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution {
private:
    vector<TreeNode *> generate(int op, int ed){
        vector<TreeNode *> ret;
        if (op > ed) {
            ret.push_back(NULL);
            return ret;
        }
        
        vector<TreeNode *> left, right;
        for (int k = op; k <= ed; ++k) {
            left = generate(op, k - 1);
            right = generate(k + 1, ed);
            
            for (auto &i: left) {
                for (auto &j: right) {
                    TreeNode *root = new TreeNode(k);
                    root->left = i;
                    root->right = j;
                    ret.push_back(root);
                }
            }
        }
        
        return ret;
    }
    
public:
    vector<TreeNode *> generateTrees(int n){
        return generate(1, n);
    }
};