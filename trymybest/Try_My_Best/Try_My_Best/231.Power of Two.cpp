#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) {
            return false;
        }
        if (n == 1) {
            return true;
        }
        
        if (n&1) {
            return false;
        }else{
            return isPowerOfTwo(n/2);
        }
        
    }
};

//int main(){
//    Solution s;
//    int x;
//    cin >> x;
//    cout << s.isPowerOfTwo(x);
//}