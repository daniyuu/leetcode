#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void print(vector<int> v, int count){
        cout << " NO." << count <<"  ";
        for (int i = 0; i < v.size(); ++i) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int index = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[index] != nums[i]) {
                index += 1;
                nums[index] = nums[i];
            }
        }
        return index + 1;
    }
};

//int main(){
//    Solution a;
//    vector<int> v;
//    int n;
//    cin >> n;
//    while (n--) {
//        int temp;
//        cin >> temp;
//        v.push_back(temp);
//    }
//    
//    for (int i = 0; i < v.size(); ++i) {
//        cout << v[i] << " ";
//    }
//    cout << endl;
//    
//    a.removeDuplicates(v);
//    for (int i = 0; i < v.size(); ++i) {
//        cout << v[i] << " ";
//    }
//}