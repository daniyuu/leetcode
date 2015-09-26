#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        
        if (nums.size() == 0) {
            return res;
        }
        
        for (int i = 0; i < nums.size(); ) {
            int val = nums[i];
            int startpos  = i;
            stringstream ss;
            ss << val;

            while (nums[++i] == ++val) {
                if (i >= nums.size()) {
                    res.push_back(ss.str());
                    return res;
                }
            }
            if(i - 1 != startpos)
                ss << "->"  << nums[i - 1];
            res.push_back(ss.str());
        }
        
        return res;
    }
};


//int main(){
//    Solution s;
//    int n;
//    cin >> n;
//    
//    vector<int> nums;
//    
//    while (n--) {
//        int t;
//        cin >> t;
//        nums.push_back(t);
//    }
//    
//    vector<string> res;
//    
//    res = s.summaryRanges(nums);
//    
//    for (int i = 0; i < res.size(); ++i) {
//        cout << res[i] << endl;
//    }
//}