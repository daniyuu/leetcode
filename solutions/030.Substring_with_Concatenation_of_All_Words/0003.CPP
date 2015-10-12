#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <string>
#include <set>
#include <queue>
#include <iostream>
#include <vector>
#include <map>
#include <numeric>

using namespace std;


long long MOD = 1000000007;
int fib[100002];
long long sub[10000];
int main()
{
    for (int x = 1, y = 1, n = 1; y <= 100000; ) {
        fib[y] = n;
        y = x + y;
        x = y - x;
        n++;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        if (ai == 1) {
            sub[1] += (sub[0] != 0) * sub[0];
            sub[0]++;
        }
        else {
            if (fib[ai] != 0) {
                sub[fib[ai]] += sub[fib[ai] - 1];
                sub[fib[ai]] %= MOD;
            }
        }
    }
    long long ans = 0;
    for (auto k : sub)
        ans = (ans + k) % MOD;
    printf("%lld\n", ans);
    return 0;
}