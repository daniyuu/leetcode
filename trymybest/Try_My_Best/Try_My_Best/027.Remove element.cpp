#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res = 0;
        int n = nums.size();
        if (n < 1) {
            return n;
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != val) {
                nums[res++] = nums[i];
            }
        }
        
        return res;
    }
};

//int main(){
//    int n;
//    vector<int> nums;
//    cin >> n;
//    while (n--) {
//        int temp;
//        cin >> temp;
//        nums.push_back(temp);
//    }
//    
//    Solution a;
//    int val;
//    cin >> val;
//    
//    for (int i  = 0; i < n; ++i) {
//        cout << nums[i] ;
//    }
//    
//    cout << " answer : " << a.removeElement(nums, val);
//    
//
//}