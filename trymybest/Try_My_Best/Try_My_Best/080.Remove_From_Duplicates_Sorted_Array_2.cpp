#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size();
        }
        
        int index = 2;
        for (int i = 2;  i < nums.size(); ++i) {
            if (nums[i] != nums[index - 2]) {
                nums[index] = nums[i];
                index++;
            }
        }
        
        return index;
        
    }
};

//
//int main(){
//    Solution a;
//    vector<int> v;
//    int n;
//    cin >> n;
//    while(n--){
//        int temp;
//        cin >> temp;
//        v.push_back(temp);
//    }
//    int l;
//    l = a.removeDuplicates(v);
//    
//    for (int i = 0 ; i < l; ++i) {
//        cout << v[i] << " ";
//    }
//    cout << endl;
//    
//    return 0;
//}