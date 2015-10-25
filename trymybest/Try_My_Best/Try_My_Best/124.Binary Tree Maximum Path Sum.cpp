/*
 * max = maxleft + maxright
 */

#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){};
};

class Solution{
private:
    int res;
    int dfs(TreeNode *root){
        if (root == NULL) {
            return 0;
        }
        
        int left_sum = max(0,dfs(root->left));
        int right_sum = max(0, dfs(root->right));
        res = max(res, left_sum + right_sum + root->val);
        return max(left_sum, right_sum) + root->val;
    }
public:
    int maxPathSum(TreeNode *root){
        res = INT_MIN;
        dfs(root);
        return res;
    }

};