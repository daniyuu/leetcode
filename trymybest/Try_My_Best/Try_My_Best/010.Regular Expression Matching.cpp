#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    // must be const
    bool isMatch(const char *s,const char *p){
        if (*p == '\0') {
            return *s == '\0';
        }
        
        if (*(p + 1) != '*') {
            if (*p == *s || (*p == '.' && *s != '\0')) {
                return isMatch(s + 1, p + 1);
            }else{
                return false;
            }
        }else{
            while (*p == *s || (*p == '.' && *s != '\0')) {
                if (isMatch(s, p + 2)) {
                    return true;
                }
                s++;
            }
            
            return isMatch(s, p + 2);
        }
    }
    
    
public:
    bool isMatch(string s, string p) {
        const char *ss = s.c_str();
        const char *pp = p.c_str();
        
        return isMatch(ss, pp);
    }
};


//int main(){
////    Solution a;
////    string s;
////    string p;
////    cin >> s;
////    cin >> p;
////    
////    cout << a.isMatch(s, p);
//    int i;
//    int sum  =0;
//    for(i=0;i<10;++i,sum+=i);
//    cout << i << endl;
//    
//}