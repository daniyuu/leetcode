#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int sz = nums.size();
        if (sz <= 0) {
            return 0;
        }
        if (sz == 1) {
            return 1;
        }
        vector<bool> left(sz, false);
        vector<int> right(sz, false);
        
        for (int i = 1; i < sz; ++i) {
            left[i] = (nums[i] - nums[i - 1]) > 0 ? true: false;
//            cout << "left " << i << left[i] <<endl;
        }
        
        for (int j = sz - 2; j >= 0; --j) {
            right[j] = (nums[j] - nums[j + 1]) > 0 ? true: false;
//            cout << "right " << j << right[j] <<endl;
        }
        
        for (int i = 0; i < sz; ++i) {
            if (left[i] && right[i]) {
//                cout << "i == " << i <<"  " << nums[i]<< endl;
                return i;
            }
        }
        
        if (nums[0] > nums[1]) {
            return 0;
        }
        
        if (nums[sz - 1] > nums[sz - 2]) {
            return sz - 1;
        }
        
        return 0;
    }
};

//int main(){
//    Solution s;
//    int sz;
//    cin >> sz;
//    vector<int> nums;
//    while (sz--) {
//        int t;
//        cin >> t;
//        nums.push_back(t);
//    }
//    
//    cout << s.findPeakElement(nums);
//}