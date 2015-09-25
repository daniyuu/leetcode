#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        if (n == 1) {
            return true;
        }
        
        if (n < 1) {
            return false;
        }
        
        unordered_set<int> showedNums;
        while (true) {
            vector<int> v;
            while (n > 0) {
                v.push_back(n % 10);
                n /= 10;
            }
            int nn = 0;
            for (int i = 0; i < v.size(); ++i) {
                nn += v[i] * v[i];
            }
            
            if (nn == 1) {
                return true;
            }else if(showedNums.find(nn) != showedNums.end()){
                return false;
            }
            
            
            n = nn;
            showedNums.insert(n);
        }
        
    }
};

//int main(){
//    Solution s;
//    int n;
//    cin >> n;
//    cout << s.isHappy(7);
//}