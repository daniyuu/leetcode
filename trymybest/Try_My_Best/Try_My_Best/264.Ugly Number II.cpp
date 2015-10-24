#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int min(int a, int b, int c){
        int minNum = a > b ? b : a;
        return minNum > c ? c: minNum;
    }
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n,0);
        ugly[0] = 1;
        
        int f2 = 2, f3 = 3, f5 = 5;
        int index2, index3, index5;
        index2 = index3 = index5 = 0;
        
        for (int i = 1; i < n ; ++i) {
            int minNum = min(f2, f3, f5);
            ugly[i] = minNum;
            
            if (f2 == minNum) {
                f2 = 2 * ugly[++index2];
            }
            
            if (f3 == minNum) {
                f3 = 3 * ugly[++index3];
            }
            
            if (f5 == minNum) {
                f5 = 5 * ugly[++index5];
            }
        }
        
        return ugly[n - 1];
    }
};