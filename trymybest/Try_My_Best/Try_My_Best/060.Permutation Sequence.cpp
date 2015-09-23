#include <iostream>
#include <string>
using namespace std;

class Solution{
private:
    
public:
    string getPermutation(int n, int k) {
        string res;
        for (int i = 0; i < n; ++i) {
            res.push_back(i + '1');
        }
        
        while (k--) {
            next_permutation(res.begin(), res.end());
        }
        
        return res;
    }
};


//Time Limit Exceeded
//int main(){
//
//}