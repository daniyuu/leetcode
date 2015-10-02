#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        int len = 1<< n;
        vector<int> res(len);
        if (n == 0) {
            return res;
        }
        for (int i = 0; i < len; ++i) {
            res[i] = (i ^ (i>>1));
        }
        return res;
    }
};