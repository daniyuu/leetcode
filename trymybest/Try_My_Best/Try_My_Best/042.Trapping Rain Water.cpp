#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left;
        vector<int> right;
        
        for (int i; i < height.size(); ++i) {
            left.push_back(0);
            right.push_back(0);
        }
        int max_left = 0, max_rigth = 0;
        
        for (int pos = 1; pos <= height.size(); ++pos) {
            max_left = max(max_left, height[pos - 1]);
            left[pos] = max_left;
        }
        
        for (int pos = height.size() - 2; pos >= 0; --pos) {
            max_rigth = max(max_rigth, height[pos + 1]);
            right[pos] = max_rigth;
        }
        
//        for (int i = 0; i < height.size(); ++i) {
//            cout << left[i] << " ";
//        }
//        cout << endl;
//        
//        for (int i = 0; i < height.size(); ++i) {
//            cout << right[i] << " ";
//        }
//        
//        cout << endl;
        
        int sum = 0;
        for (int pos = 0; pos < height.size(); ++pos) {
            int peak;
            peak = min(left[pos], right[pos]) - height[pos];
//            cout << "peak == " << peak <<endl;
            if (peak > 0) {
                sum += peak;
            }
            
        }
        
        return sum;
    }
};

//int main(){
//    Solution s;
//    vector<int> v;
//    int n;
//    cin >> n;
//    while (n--) {
//        int temp;
//        cin >> temp;
//        v.push_back(temp);
//    }
//    
//    cout << s.trap(v);
//}