class Solution {
private:
	void dfs(vector<vector<int> > &ans, vector<int> single, vector<int> &candi, int cur, int rest){
		if(candi.size() <= cur || rest < 0){
			return;
		}
		if(rest == 0 ){
			ans.push_back(single);
			return;
		}

		single.push_back(candi[cur]);
		dfs(ans,single,candi,cur,rest - candi[cur]);

		single.pop_back();

		dfs(ans,single,candi,cur + 1, rest);
	}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        vector<int> single;
        sort(candidates.begin(), candidates.end());
        dfs(ans, single, candidates, 0, target);
        return ans;
    }
};