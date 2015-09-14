class Solution {
public:
    int jump(vector<int>& nums) {
    	int pre = 0;
    	int curr = 0;
    	int step = 0;

    	for(int i = 0; i < nums.size(); ++i){
    		if(i > curr){
    			return -1;
    		}

    		if(i > pre){
    			pre = curr;
    			step++;
    		}

    		curr = max(curr, i + nums[i]);
    	}

    	return step;
        
    }
};