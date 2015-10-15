#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>> &res, vector<int> &v, int cur, int rest, int n){
        if (rest == 0) {
            res.push_back(v);
            return;
        }
        v.push_back(0);
        
        int len = v.size();
        for (int i = cur; i <= n - rest + 1; ++i) {
            v[len - 1] = i;
            dfs(res, v, i + 1, rest - 1, n);
        }
        v.pop_back();
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if (n < k || !n || !k) {
            return res;
        }
        vector<int> v;
        dfs(res, v, 1, k, n);
        return res;
    }
};

int main(){
    Solution s;
    int n,k;
    cin >> n >> k;
    vector<vector<int>> res;
    res = s.combine(n, k);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[0].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}