#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int> &nums){
        if (nums.size() <= 1) {
            return 0;
        }
        
        int res = 0;
        
        vector<int> dp(nums.size(),0);
        
        for (int i = 2; i < nums.size() ; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2]) + nums[i];
            res = max(res, dp[i]);
        }
        
        return res;
    
    }
};