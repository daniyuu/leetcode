#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        if(s.length() <= numRows) return s;
        
        int step = numRows * 2 - 2;
        int len = s.length();
        
        string res = "";
        
        for (int i = 0 ; i < len; i+=step) {
            res += s[i];
        }
        
        for(int i = 1; i < numRows - 1; ++i){
            for (int j = i; j < len; j += step) {
                res+=s[j];
                if(j + (step - i * 2) < len){
                    res += s[j + (step - i * 2)];
                }
            }
        }
        
        for (int i = numRows - 1; i < len; i+=step) {
            res += s[i];
        }
        
        return res;
        
    }
};
//
//int main(){
//    cout << "her" <<endl;
//    Solution a;
//    string s;
//    cin >> s;
//    int n;
//    cin >> n;
//    cout << a.convert(s, n);
//}