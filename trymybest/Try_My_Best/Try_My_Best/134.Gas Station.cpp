#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int cur_station = 0;
        int n = gas.size();
        int k = 0;
        
        for (start = 0; start < n; start += k + 1) {
            int sum_gas = 0;
            for (k = 0; k < n; ++k) {
                cur_station = (start + k) % n;
                sum_gas += gas[cur_station] - cost[cur_station];
                if (sum_gas < 0) {
                    break;
                }
            }
            if (sum_gas >= 0)
                return start;
        }
        
        return -1;
    }
};