#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>> &res, vector<int> &v, int &sum, int k, int n, int pos){
        if (k == 0) {
            if (sum == n) {
                res.push_back(v);
            }
            return;
        }
        
        for (int i = pos; i <= 9;  ++i) {
            if (sum + i > n) {
                break;
            }
            v.push_back(i);
            sum += i;
            dfs(res, v, sum, k - 1, n, i + 1);
            v.pop_back();
            sum -= i;
        }
        
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> v;
        int sum = 0;
        dfs(res,v,sum, k, n, 1);
        return res;
    }
};