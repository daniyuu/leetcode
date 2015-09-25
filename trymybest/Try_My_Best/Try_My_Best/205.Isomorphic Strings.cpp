#include <string>
#include <iostream>
#include <map>
using namespace std;

class Solution {
private:
    bool isSubIsomorphic(string s, string t){
        if (s.length() != t.length()) {
            return false;
        }
        
        if (s.length() == 0) {
            return true;
        }
        
        map<char,char> m;
        map<char,char>::iterator it;
        
        for (int i = 0; i < s.length(); ++i) {
            it = m.find(s[i]);
            if (it == m.end()) {
                m[s[i]] = t[i];
            }else{
                if (m[s[i]] != t[i]) {
                    return  false;
                }
            }
        }
        
        return true;
    
    }
public:
    bool isIsomorphic(string s, string t) {
        return isSubIsomorphic(s, t) && isSubIsomorphic(t, s);
    }
};
//
//int main(){
//    Solution a;
//    string s, t;
//    cin >> s;
//    cin >> t;
//    
//    cout << a.isIsomorphic(s, t);
//    
//}