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
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    template<typename InputIterator>
    TreeNode *buildTree(InputIterator in_first, InputIterator in_last, InputIterator post_first, InputIterator post_last){
        if (in_first == in_last) {
            return nullptr;
        }
        
        if (post_first == post_last) {
            return nullptr;
        }
        
        auto val = *prev(post_last);
        TreeNode *root = new TreeNode(val);
        
        auto in_root_pos = find(in_first, in_last, val);
        auto left_size = distance(in_first, in_root_pos);
        auto post_left_last = next(post_first, left_size);
        
        root->left = buildTree(in_first, in_root_pos, post_first, post_left_last);
        root->right = buildTree(next(in_root_pos), in_last, post_left_last, prev(post_last));
        
        return root;
        
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(begin(inorder), end(inorder), begin(postorder), end(postorder));
    }
};