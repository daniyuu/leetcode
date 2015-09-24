#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> temp;
        int numOfZeros = 0;
        
        while (!nums.empty()) {
            int t = nums.back();
            nums.pop_back();
            if (t) {
                temp.push_back(t);
            }else{
                numOfZeros++;
            }
        }
        
        while (!temp.empty()) {
            int t = temp.back();
            temp.pop_back();
            nums.push_back(t);
        }
        
        while (numOfZeros--) {
            nums.push_back(0);
        }
        
    }
};