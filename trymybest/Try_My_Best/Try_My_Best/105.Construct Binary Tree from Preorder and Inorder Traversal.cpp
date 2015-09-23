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

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    template<typename InputIterator>
    TreeNode *buildTree(InputIterator pre_first, InputIterator pre_last, InputIterator in_first, InputIterator in_last){
        if (pre_first == pre_last) {
            return nullptr;
        }
        if (in_first == in_last) {
            return nullptr;
        }
        
        auto root = new TreeNode(*pre_first);
        
        auto inRootPos = find(in_first, in_last, *pre_first);
        auto leftsize = distance(in_first, inRootPos);
        
        root->left = buildTree(next(pre_first), next(pre_first, leftsize + 1), in_first, next(in_first, leftsize));
        
        root->right = buildTree(next(pre_first, leftsize + 1), pre_last, next(inRootPos), in_last);
        
        return root;
        
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(begin(preorder), end(preorder), begin(inorder), end(inorder));
    }
};

//int main(){
//    
//}

