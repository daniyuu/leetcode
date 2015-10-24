/*
 * 提前终止到一些条件
 * 1.只判断根号n以下的就够了
 * 2.p^2 + xp也可以提前去掉
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool isPrime(int n){
        if ( n <= 1 ) {
            return false;
        }
        
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        
        return true;
    
    }
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n,true);
        
        for (int i = 2; i * i < n; i++) {
            if (!isPrime[i]) continue;
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) count++;
        }
        return count;
    }
};