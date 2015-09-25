#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            map<int, int>::iterator l_it;
            l_it = m.find(nums[i]);
            if (l_it == m.end()) {
                m[nums[i]] = 1;
            }else{
                m[nums[i]]++;
//                cout << m[nums[i]] << "  * " << endl;
                if (m[nums[i]] > 1) {
                    return true;
                }
            }
        }
        return false;
    }
};
//
//int main(){
//    Solution s;
//    vector<int> nums;
//    int n;
//    cin >> n;
//    while (n--) {
//        int t;
//        cin >> t;
//        nums.push_back(t);
//    }
//    cout << s.containsDuplicate(nums);
//    
//}