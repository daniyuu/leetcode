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
    template<typename InputInterator>
    TreeNode *sortedArrayToBST(InputInterator first, InputInterator last){
        int length = distance(first, last);
        
        if (length <= 0) {
            return nullptr;
        }
        
        auto mid = first + length/2;
        TreeNode *root = new TreeNode(*mid);
        root->left = sortedArrayToBST(first, mid);
        root->right = sortedArrayToBST(mid + 1, last);
        
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums.begin(), nums.end());
    }
};