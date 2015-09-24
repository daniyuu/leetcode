class Solution {
public:
    int climbStairs(int n) {
        int pre = 0;
        int cur = 1;
        for (int i = 1; i <= n; ++i) {
            int temp = cur;
            cur += pre;
            pre = temp;
        }
        
        return cur;
    }
};