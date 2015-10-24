/*
 * 只能由 2 3 5 组成 所以能约掉就行了
 */

class Solution {
public:
    bool isUgly(int num) {
        if (num == 0) {
            return false;
        }
        
        if (num == 1) {
            return true;
        }
        while (num % 2 == 0) {
            num /= 2;
        }
        
        while (num % 3 == 0) {
            num /= 3;
        }
        
        while (num % 5 == 0) {
            num /= 5;
        }
        
        if (num == 1) {
            return true;
        }else{
            return false;
        }
    }
};