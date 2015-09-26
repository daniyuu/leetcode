#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() == 0 || b.length() == 0) {
            return "";
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string res = "";
        
        int alen = a.length();
        int blen = b.length();
        
        
        bool carry = false;
        for (int i = 0; i < alen || i < blen; ++i) {
            if (i >= alen) {
                a += '0';
            }
            if (i >= blen) {
                b += '0';
            }
            
            if (a[i] == '1' && b[i] == '1') {
//                cout << " 1 + 1 = " << endl;
                a[i] = carry + '0';
                carry = 1;
                continue;
            }else if( a[i] == '1' || b[i] == '1'){
                a[i] = !carry + '0';
                continue;
            }else{
                a[i] = carry + '0';
                carry = 0;
                continue;
            }
        }
        
        if (carry) {
//            cout << "here" << endl;
            a += '1';
        }
        
        reverse(a.begin(), a.end());
        
        return a;
        
    }
};

//int main(){
//    Solution s;
//    string a, b;
//    cin >> a;
//    cin >> b;
//    cout << s.addBinary(a, b);
//}