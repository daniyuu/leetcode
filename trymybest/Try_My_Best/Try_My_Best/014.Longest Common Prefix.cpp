#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        
        for (int i = 0; i < strs[0].length(); ++i) {
            for (int j = 1; j < strs.size(); ++j) {
                if (i >= strs[j].length() || strs[j][i] != strs[0][i]) {
                    return strs[0].substr(0,i);
                }
            }
        }
        
        return strs[0];
        
    }
};

//int main(){
//    Solution s;
//    int n;
//    cin >> n;
//    vector<string> v;
//    while (n--) {
//        string s;
//        cin >> s;
//        v.push_back(s);
//    }
//    
//    cout << s.longestCommonPrefix(v);
//
//}