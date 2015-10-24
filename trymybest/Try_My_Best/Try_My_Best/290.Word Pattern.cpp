#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

class Solution {
private:
    void split(string& s, string& delim, vector< string > * ret)
    {
        size_t last = 0;
        size_t index=s.find_first_of(delim,last);
        while (index!= string::npos)
        {
            ret->push_back(s.substr(last,index-last));
            last=index+1;
            index=s.find_first_of(delim,last);
        }
        if (index-last>0)
        {
            ret->push_back(s.substr(last,index-last));
        }  
    }
public:
    bool wordPattern(string pattern, string str) {
        map<char,string> m1;
        map<string, char> m2;
        
        vector<string> vect;
        string delim = " ";
        split(str, delim, &vect);
  
        if (pattern.size() != vect.size()) {
            return false;
        }
        
        map<char, string>::iterator it1;
        map<string, char>::iterator it2;
    
        for (int i = 0; i < pattern.size(); ++i) {
            it1 = m1.find(pattern[i]);
            it2 = m2.find(vect[i]);
            
            if (it1  == m1.end() && it2 == m2.end()) {
                m1[pattern[i]] = vect[i];
                m2[vect[i]] = pattern[i];
                
            }else if(it1 == m1.end() && it2 != m2.end()){
                return false;
            }else{
                if (m1[pattern[i]] != vect[i]) {
                    return false;
                }
            }
            
        }
        
        return true;
    }
};

//int main(){
//    Solution s;
//    cout << s.wordPattern("abba","dog cat cat dog");
//}