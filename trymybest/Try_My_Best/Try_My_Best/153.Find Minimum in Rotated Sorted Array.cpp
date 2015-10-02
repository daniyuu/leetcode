#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int mid = 0;
        
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (nums[l] <= nums[mid] && nums[mid] <= nums[r]) {
                return nums[l];
            }else if (nums[l] <= nums[mid]){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        
        return nums[0];
    }
};