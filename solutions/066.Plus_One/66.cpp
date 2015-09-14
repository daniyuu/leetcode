class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = true;
        for(int i = digits.size() - 1; i >= 0; --i){
        	carry = ((digits[i] + 1) % 10  == 0);
        	if(carry){
        		digits[i] = 0;
        	}else{
        		digits[i]++;
        		return digits;
        	}
        }

        vector<int> res(digits.size() + 1, 0);
        res[0] = 1;
        return res;
    }
};