class Solution {
private:
	void dfs(vector<vector<int> > &ans, vector<int> &single, vector<int> &nums; int depth){
		if(depth == nums.size()){
			ans.push_back(single);
			return;
		}

		dfs(ans,single,nums, depth + 1);

		single.push_back(nums[depth]);
		dfs(ans,single,nums, depth + 1);
		single.pop_back();
	}
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> single;
        sort(nums.begin(), nums.end());
        dfs(ans,single,nums,0);
        return ans;
    }
};