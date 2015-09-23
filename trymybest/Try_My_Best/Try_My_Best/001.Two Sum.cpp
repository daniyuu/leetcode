#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> result;
        for (int i = 0; i< nums.size(); ++i) {
            m[nums[i]] = i + 1;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            int gap = target - nums[i];
            if (m.find(gap) != m.end() && m[gap] > i + 1) {
                result.push_back(i + 1);
                result.push_back(m[gap]);
            }
        }
        
        return result;
    }
};
//
//int main(){
//    Solution a;
//    int n;
//    vector<int> nums;
//    cin >> n;
//    while (n--) {
//        int temp;
//        cin >> temp;
//        nums.push_back(temp);
//    }
//    
//    int target;
//    cin >> target;
//    a.twoSum(nums, target);
//}