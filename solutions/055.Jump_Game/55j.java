public class Solution {
    public boolean canJump(int[] nums) {
    	int n = nums.length;
    	int maxstep = nums[0];
        
        if(n < 2){
        	return true;
        }

        for(int i = 1; i < n; ++i){
        	if(maxstep == 0){
        		return false;
        	}
        	maxstep--;
        	maxstep = Math.max(maxstep, nums[i]);

        	if(maxstep + i >= n - 1){
        		return true;
        	}
        }
        return false;

    }
}