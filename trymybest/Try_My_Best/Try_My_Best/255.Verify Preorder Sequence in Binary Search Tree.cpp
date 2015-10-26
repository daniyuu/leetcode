/*
* Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.
* You may assume each number in the sequence is unique.
* Follow up:
* Could you do it using only constant space complexity?
*
* http://blog.csdn.net/pointbreak1/article/details/48991489
*/


#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool verifyPreorder(vector<int> preorder){
        int low = INT_MIN;
        stack<int> s;
        
        for (int i = 0; i < preorder.size(); ++i) {
            if (preorder[i] < low) {
                return false;
            }
            while (!s.empty() && preorder[i] > s.top()) {
                low = s.top();
                s.pop();
            }
            s.push(preorder[i]);
        }
        
        return true;
        
    }
};

