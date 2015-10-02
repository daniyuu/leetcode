#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> res;
        map<int, int>::iterator it;
        
        for (int i = 0; i < nums.size(); ++i) {
            it = res.find(nums[i]);
            if (it == res.end()) {
                res[nums[i]] = 1;
            }else{
                res[nums[i]] += 1;
            }
        }
        
        for (it = res.begin(); it != res.end(); ++it) {
//            cout << it->first << " " << it->second << endl;
            if (it->second == 1) {
                return it->first;
            }
        }
        
        return -1;
        
    }
};

//int main(){
//    Solution s;
//    int n;
//    cin >> n;
//    vector<int> nums;
//    while (n--) {
//        int t;
//        cin >> t;
//        nums.push_back(t);
//    }
//    int res;
//    res = s.singleNumber(nums);
//
//    cout << res <<  endl;
//
//}