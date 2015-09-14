class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        int res = nums[0] + nums[1] + nums[2];

        sort(nums.begin(), nums.end());

        for(int i = 0; i <= len - 3; ++i){
        	int j = i + 1;
        	int k = len - 1;
        	while(j < k){
        		int sum = nums[i] + nums[j] + nums[k];
        		if(abs(sum - target) < abs(res - target)){
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
};