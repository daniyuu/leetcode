//
//  main.cpp
//  Median_of_two_sorted_arrays
//
//  Created by 陈悦莹 on 9/17/15.
//  Copyright © 2015 陈悦莹. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2){
        int n = nums1.size();
        int m = nums2.size();
    
        vector<int> C;
        
        int pa = 0, pb = 0;
        
        if (n == 0) {
            while (pb != m) {
                C.push_back(nums2[pb++]);
            }
            if (m % 2 == 1)
                return C[m/2];
            else
                return (C[m/2 - 1] + C[m/2]) / 2.0;
        }
        
        if (m == 0) {
            while (pa != n) {
                C.push_back(nums1[pa++]);
            }
            if (n % 2 == 1)
                return C[n/2];
            else
                return (C[n/2 - 1] + C[n/2]) / 2.0;
        }
//        cout << "n == " << n <<endl;
//        cout << "m == " << m <<endl;
        while (pa < n || pb < m) {
//            cout << "pa == " << pa << endl;
//            cout << "pb == " << pb << endl;
            if (pa == n) {
                C.push_back(nums2[pb++]);
                continue;
            }
            if (pb == m) {
                C.push_back(nums1[pa++]);
                continue;
            }
            if(pa > n || pb > m){
                break;
            }
            if(nums1[pa] > nums2[pb]){
                C.push_back(nums2[pb++]);
            }else{
                C.push_back(nums1[pa++]);
            }
            
        }
//        cout << "c" << endl;
//        for (int i = 0; i < C.size(); ++i) {
//            cout << C[i];
//        }
        
        if ((n + m) % 2 == 1)
            return C[(n+m)/2];
        else
            return (C[(n+m)/2 - 1] + C[(n+m)/2]) / 2.0;
        
    }
};




int main(int argc, const char * argv[]) {
    int n, m;
    vector<int> A,B;
    Solution s;
    
    while(cin>> n){
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            A.push_back(a);
        
        }
        cin >> m;
        for (int j = 0; j < m; ++j) {
            int b;
            cin >> b;
            B.push_back(b);
        }
    
        cout << s.findMedianSortedArrays(A,B);
    }
    
    
    return 0;
}
