#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int first = 0;
        int last = n;
        
        while (first != last) {
            int mid = first + (last - first) / 2;
            
            if(nums[mid] == target){
                return mid;
            }
            if (nums[first] < nums[mid]) {
                if(nums[first] <= target && target < nums[last - 1]){
                    last = mid;
                }else{
                    first = mid + 1;
                }
            }else if(nums[mid] < nums[last]){
                if(nums[mid] < target && target <= nums[last - 1]){
                    first = mid + 1;
                }else{
                    last = mid;
                }
            }else{
                first++;
            }
            
            
        }
        
        return -1;
    }

 
};

//int main(){
//    return 0;
//}