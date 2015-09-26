#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
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
private:
    void dfs(TreeNode *root, string unit, vector<string> &result){
        int val = root->val;
        string newUnit = unit;
        
        
        stringstream ss;
        ss << val;
        
        newUnit += ss.str();

        
        if (root->left == NULL && root->right == NULL) {
            result.push_back(newUnit);
            return;
        }
        newUnit += "->";
        
        if (root->left != NULL) {
            dfs(root->left, newUnit, result);
        }
        
        if (root->right != NULL) {
            dfs(root->right, newUnit, result);
        }
    }
    
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        
        if (root == NULL) {
            return result;
        }
        dfs(root, "", result);
        
        return result;
    }
};

//int main(){
//    Solution s;
//    TreeNode *root;
//    root->val = 1;
//    root->left = NULL;
//    root->right = NULL;
//    
//    vector<string> res;
//    res = s.binaryTreePaths(root);
//    
//    for (int i = 0; i < res.size(); ++i) {
//        cout << res[i] << " " ;
//    }
//    
//    int val = -10;
//    stringstream ss;
//    ss << val;
//    cout << ss.str();
//    
//}