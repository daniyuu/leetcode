
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 0);
        res[0] = 1;
        
        for (int row = 1; row <= rowIndex; ++row) {
            int pre = res[0];
            for (int j = 1; j < row; ++j) {
                int temp = pre;
                pre = res[j];
                res[j] = temp + res[j];
            }
            res[row] = 1;
        }
        return res;
    }
};

//int main(){
//    Solution s;
//    int n;
//    cin >> n;
//    vector<int> res = s.getRow(n);
//    
//    for (int i = 0; i < res.size(); ++i) {
//        cout << res[i] << " " ;
//    }
//
//}