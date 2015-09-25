#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k == 0 || nums.size() <= 1) {
            return false;
        }
        bool flag = false;
        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            map<int, int>::iterator it;
            it = m.find(nums[i]);
            if (it == m.end()) {
//                cout << "here " << nums[i];
                m[nums[i]] = i;
            }else{
                flag = true;
                if (i - m[nums[i]] <= k) {
                    return true;
                }else{
                    m[nums[i]] = i;
                }
            }
        }
        
        return false;
    }
};

//int main(){
//    Solution s;
//    vector<int> v;
//    int n;
//    cin >> n;
//    while (n--) {
//        int t;
//        cin >> t;
//        v.push_back(t);
//    }
//    int k;
//    cin >> k;
//    cout << s.containsNearbyDuplicate(v, k);
//}