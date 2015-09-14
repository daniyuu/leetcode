class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        int tar = 0;
        int len = nums.size();

        if(len <= 2){
        	return res;
        }

        sort(nums.begin(), nums.end());
        for(int i = 0; i <= len - 3; ++i){
        	int j = i + 1;
        	int k = len - 1;

        	while(j < k){
        		int sum = nums[i] + nums[j] + nums[k];
        		if(sum > tar){
        			--k;
        		}else if(sum < tar){
        			++j;
        		}else{
        			res.push_back({nums[i], nums[j], nums[k]});
        			--k;
        			++j;

        			while(j < k && nums[j] == nums[j - 1])
        				++j;
        			while(j < k && nums[k] == nums[k + 1])
        				--k;
        		}
        	}

        	while (i <= len - 3 && num[i] == num[i + 1])
                ++i;
        }

    }
};