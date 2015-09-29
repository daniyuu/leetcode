#include <map>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() <= 1 ) {
            return nums.size();
        }
        
        unordered_map<int, bool> used;
        
        for(auto i:nums){
            used[i] = false;
        }
        
        int longest = 0;
        
        for(auto i:nums){
            if(used[i]){
                continue;
            }
            
            int length = 1;
            
            for (int j = i + 1; used.find(j) != used.end() ; ++j) {
                used[j] = true;
                ++length;
            }
            
            for (int j = i - 1; used.find(j) != used.end(); --j) {
                used[j] = true;
                ++length;
            }
            
            longest = max(longest, length);
            
        }
        
        
        return longest;
        
        
    }
};

//class A{
//public:
//    int a;
//    int b;
//
//    A(int aa, int bb){
//        a = aa--;
//        b = a* bb;
//    }
//};
//
//int main(){
//    int n[] [3] = {10,20,30,40,50,60};
//    int (*p) [3];
//    p = n;
//    cout << p[0][0] << ", " << *(p[0] + 1) << ", " <<(*p)[2] << endl;
//    
//}