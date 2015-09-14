class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int res = 0;
        for(int i = 0; i < height.size(); ++i){
        	if(height[i] > height[i + 1] || i + 1 == height.size()){
        		int mmin = INT_MAX;
        		for(int j = i; j >=0; --j){
        			mmin = min(mmin, height[j]);
        			res = max(res, mmin * (i - j + 1));
        		}
        	}
        }
        return res;
    }
};