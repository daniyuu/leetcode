public class Solution {
    public boolean isValid(String s) {
    	Stack<Integer> stk = new Stack<Integer>();

    	for(int i = 0; i < s.length(); ++i){
    		int pos = "(){}[]".indexOf(s.substring(i, i + 1));
    		if(pos % 2 == 1){
    			if(stk.isEmpty() || stk.pop() != pos - 1){
    				return false;
    			}
    		}else{
    			stk.push(pos);
    		}
    	}
        
        return stk.isEmpty();
    }
}