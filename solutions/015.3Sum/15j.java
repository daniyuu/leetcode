public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
    	List<List<Integer> > res = new ArrayList<List<Integer> >();
    	int len = nums.length;
    	int tar = 0;

    	Arrays.sort(nums);

        for (int i = 0; i <= len - 3; i++) {
            // first number : num[i]
            int j = i + 1;	// second number
            int k = len - 1;	// third number
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] < tar) {
                    ++j;
                } else if (nums[i] + nums[j] + nums[k] > tar) {
                    --k;
                } else {
                    res.add(Arrays.asList(nums[i], nums[j], nums[k]));
                    ++j;
                    --k;
                    // folowing 3 while can avoid the duplications
                    while (j < k && nums[j] == nums[j - 1])
                        ++j;
                    while (j < k && nums[k] == nums[k + 1])
                        --k;
                }
            }
            while (i <= len - 3 && nums[i] == nums[i + 1])
                ++i;
        }
        return res;

        
    }
}