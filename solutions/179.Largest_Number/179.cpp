class Solution {
private:
    static bool cmp(string a, string b) {
        return (a + b) > (b + a);
    }
	
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(auto &i : nums){
        	v.push_back(to_string(i));
        }

        sort(v.begin(), v.end(), cmp);

        string ans;

        if (v[0] == "0")
            return "0";
        for (auto &i : v)
            ans += i;

        return ans;

    }
};