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
	void orderHelper(vector<int> &res, TreeNode *cur){
		if(!cur){
			return;
		}
		if(cur->left){
			orderHelper(res,cur->left);
		}
		if(cur->right){
			orderHelper(res,cur->right);
		}
		res.push_back(cur->val);
	}
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        orderHelper(res, root);
        return res;

    }
};