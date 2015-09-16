class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        const int size = 32;
        bitset<size> bits(n);
        for(int i = 0; i < size/2; ++i){
        	int temp = bits[i];
        	bits[i] = bits[size - i - 1];
        	bits[size - i - 1] = temp;
        }
        return (uint32_t) bits.to_ulong();
        
    }
};