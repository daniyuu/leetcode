class Solution {
private:
	void dfs(vector<vector<int> > &ans, vector<int> &single, vector<int> &candidates, int cur, int rest){
		
		if (rest == 0) {
            // to avoid [[1,1,1], 2]
            if (!single.empty() && cur < candidates.size() && single[single.size() - 1] == candidates[cur])
                return;
            ans.push_back(single);
            return;
        }

        if(candidates.size() <= cur || rest < 0){
			return;
		}

		single.push_back(candidates[cur]);
		dfs(ans,single,candidates, cur + 1, rest - candidates[cur]);
		single.pop_back();

		if (!single.empty() && single[single.size() - 1] == candidates[cur])
            return;
        
		dfs(ans,single,candidates,cur+1,rest);


	}
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        vector<int> single;
        sort(candidates.begin(), candidates.end());
        dfs(ans,single,candidates,0,target);

        return ans;
    }
};