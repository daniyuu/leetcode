#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        set<int> res;
        set<int>::iterator it;
       
        while (!nums.empty()) {
            int back = nums.back();
            nums.pop_back();
//            cout << "back " << back << endl;
            it = res.find(back);
            if (it == res.end()) {
                res.insert(back);
//                cout << "insert" << endl;
            }else{
                res.erase(back);
            }
        }
        
        for(it = res.begin();it != res.end();it++){
//            cout << *it << endl;
            nums.push_back(*it);
        }
        
        
        return nums;
    }
};
//
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
//    vector<int> res;
//    res = s.singleNumber(nums);
//    
//    for (int i = 0; i < nums.size(); ++i) {
//        cout << nums[i] << " ";
//    }
//    cout << endl;
//
//}