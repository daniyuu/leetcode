public class Solution {
    public int jump(int[] nums) {
        int pre = 0;
    	int curr = 0;
    	int step = 0;

    	for(int i = 0; i < nums.length; ++i){
    		if(i > curr){
    			return -1;
    		}

    		if(i > pre){
    			pre = curr;
    			step++;
    		}

    		curr = Math.max(curr, i + nums[i]);
    	}

    	return step;
    }
}