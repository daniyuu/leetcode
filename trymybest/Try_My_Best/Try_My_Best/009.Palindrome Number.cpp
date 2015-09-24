#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        vector<int> temp;
        int cnt = 0;
        
        while (x) {
            cnt++;
            int t = x % 10;
            temp.push_back(t);
            x /= 10;
        }
        
        for (int i = 0;  i < cnt; ++i) {
            if (temp[i] != temp[cnt - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};

//int main(){
//    Solution s;
//    int a;
//    cin >> a;
//    cout << s.isPalindrome(a);
//}