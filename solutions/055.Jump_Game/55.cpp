class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
    	int maxstep = nums[0];
        
        if(n < 2){
        	return true;
        }

        for(int i = 1; i < n; ++i){
        	if(maxstep == 0){
        		return false;
        	}
        	maxstep--;
        	maxstep = max(maxstep, nums[i]);

        	if(maxstep + i >= n - 1){
        		return true;
        	}
        }

    }
};