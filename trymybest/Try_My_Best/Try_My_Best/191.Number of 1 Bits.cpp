#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int hammingWeight(uint32_t n) {
        const int size = 32;
        bitset<size> bits(n);
        return bits.count();
    }
};