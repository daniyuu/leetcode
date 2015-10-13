#include <iostream>
#include <vector>
//hello, word -> word hello,
using namespace std;

class Solution{
private:
    void trimString(string & str ){
        
        int s = str.find_first_not_of(" ");
        
        int e = str.find_last_not_of(" ");
        
        if (s == -1 || e == -1) {
            str = "";
        }else{
            str = str.substr(s,e-s+1);
        }
        return;
    }
    
    void removeblank(string &str){
        string nstr = "";
        for (int i = 0; i < str.length(); ) {
            nstr += str[i];
            if (str[i] != ' ') {
                ++i;
            }else{
                while (str[++i] == ' ') {}
                continue;
            }
        }
        
        str = nstr;
    
    }
public:
    void reverseWords(string &s){
        if (s.length() == 0) {
            return;
        }
        
        trimString(s);
        
        if (s.length() == 0) {
            return;
        }
        
        removeblank(s);
        
        reverse(s.begin(), s.end());
        
        
        int first = 0;
        int last = 0;
        while (first < s.length() - 1) {
            int index = 0;
            while (s[first + index] != ' ' && (first + index) < s.length()) {
                index++;
            }
            reverse(s.begin()+ first, s.begin() + first + index);
            first += index + 1;
        }
    }
};

//int main(){
//    Solution s;
//    string a = "  1    2 ";
//    s.reverseWords(a);
//    cout << a ;
////    cout << a.substr(1);
//}