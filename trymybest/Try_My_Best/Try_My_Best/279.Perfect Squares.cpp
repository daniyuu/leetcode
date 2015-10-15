#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> v(n + 1, 0);
        v[1] = 1;
        
        for (int i = 2; i <= n; ++i) {
            int res = INT_MAX;
            int j = 1;
            while (j * j <= i) {
                if (j * j == i) {
                    res = 1;
                    break;
                }
                
                res = min(res, v[i - j * j] + 1);
                ++j;
            }
            v[i] = res;
        }
        
        return v[n];
    }
};