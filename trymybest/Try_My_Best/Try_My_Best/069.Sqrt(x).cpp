#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) {
            return x;
        }
        int left = 1;
        int right = x/2;
        int last_mid = 0;
        
        while (left<=right) {
            int mid = left + (right - left)/2;
            if (x / mid > mid) {
                left = mid + 1;
                last_mid = mid;
            }else if (x / mid < mid){
                right = mid - 1;
            }else{
                return mid;
            }
        }
        return last_mid;
    }
};

//int main(){
//    Solution s;
//    int a = 2;
//    cout << s.mySqrt(a);
//}