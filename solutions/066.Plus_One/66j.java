public class Solution {
    public int[] plusOne(int[] digits) {
    	boolean carry = true;
    	for(int i = digits.length - 1; i >= 0; --i){
    		carry = ((digits[i] + 1) % 10 == 0);
    		if(carry){
    			digits[i] = 0;
    		}else{
    			digits[i]++;
    			return digits;
    		}
    	}

    	int[] res = new int[digits.length + 1];
    	res[0] =1;
    	return res;
        
    }
}