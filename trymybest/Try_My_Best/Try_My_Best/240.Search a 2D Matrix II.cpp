#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        
        int i = 0;
        int j = matrix[0].size() - 1;
        
        while (i < matrix.size() && j >= 0) {
            int temp = matrix[i][j];
            if (target == temp) {
                return true;
            }else if (target < temp){
                --j;
            }else{
                ++i;
            }
        }
        
        return false;
    }
};