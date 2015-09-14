public class Solution {
    public int threeSumClosest(int[] nums, int target) {
    	Arrays.sort(nums);
        int len = nums.length;
        int res = nums[0] + nums[1] + nums[2];

       

        for(int i = 0; i <= len - 3; ++i){
        	int j = i + 1;
        	int k = len - 1;
        	while(j < k){
        		int sum = nums[i] + nums[j] + nums[k];
        		if(Math.abs(sum - target) < Math.abs(res - target)){
        			res = sum;
        		}
        		if (sum < target) {
                    ++j;
                } else if (sum > target) {
                    --k;
                } else {
                    ++j;
                    --k;
                }
        	}
        }
        return res;
    }
}