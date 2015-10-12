#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int res = nums[0];
        if (nums.size() <= 0) {
            return 0;
        }
        for (int i = 1; i < nums.size(); ++i) {
            if (sum < 0) {
                sum = nums[i];
            }else{
                sum += nums[i];
            }
            res = max(res, sum);
        }
        
        return res;
    }
};

//int main(){}