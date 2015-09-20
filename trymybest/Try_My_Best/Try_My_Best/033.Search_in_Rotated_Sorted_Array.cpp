#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }
        
        int first = 0;
        int last = nums.size();
        
        
        while(first != last){
            int mid = first + (last - first) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            
            if(nums[first] < nums[mid]){
                if (nums[first] <= target && target < nums[mid]) {
                    last = mid;
                }else{
                    first = mid + 1;
                }
            }else{
                if (nums[mid] < target && target <= nums[last - 1]) {
                    first = mid + 1;
                }else{
                    last = mid;
                }
            }
        }
        return -1;
    }
};


//int main(){
//
//}