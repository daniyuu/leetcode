#include <iostream>
#include <vector>
using namespace std;

//class Solution {
//public:
//    int missingNumber(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        for (int i = 0; i < nums.size(); ++i) {
//            if (nums[i] != i) {
////                cout << " *** " << nums[i] << endl;
//                return nums[i] - 1;
//            }
//        }
//        return nums[nums.size() - 1] + 1;
//    }
//};

// 也不比上一种快多少呀
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int l = 0;
        int r = nums.size() - 1;
        int mid = 0;
        
        if (l == r) {
            if (nums[0] == 0) {
                return 1;
            }else{
                return 0;
            }
        }
        
        while (l <= r) {
            mid = l + (r - l) / 2;
//            cout << "mid = " << mid <<"  " << nums[mid]<< endl;
            if (nums[mid] == mid) {
                l = mid + 1;
            }else if(nums[mid] > mid){
                if (mid == 0) {
                    return 0;
                }
                if (nums[mid - 1] == mid - 1 ) {
                    return mid;
                }else{
                    r = mid;
                }
            }
        }
        
        return nums[nums.size() - 1] + 1;
    }
};

//int main(){
//    int n;
//    cin >> n;
//    vector<int> nums;
//    while (n--) {
//        int t;
//        cin >> t;
//        nums.push_back(t);
//    }
//    Solution s;
//    cout << s.missingNumber(nums) << endl;
//}