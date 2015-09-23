
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int len = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i <= len - 4; ++i) {
            for (int j = i + 1; j <= len - 3; ++j) {
                int p = j + 1;
                int q = len - 1;
                while (p < q) {
                    int sum = nums[i] + nums[j] + nums[p] + nums[q];
                    if (sum > target) {
                        --q;
                    }else if (sum < target){
                        ++p;
                    }else{
                        res.push_back({nums[i], nums[j], nums[p], nums[q]});
                        ++p;
                        --q;
                        while (p < q && nums[p] == nums[p - 1])
                            ++p;
                        while (p < q && nums[q] == nums[q + 1])
                            --q;
                        
                    }
                }
                while (j < len && nums[j] == nums[j + 1]) {
                    ++j;
                }
                
            }
            while (i < len && nums[i] == nums[i + 1]) {
                ++i;
            }
            
            
        }
        return res;
    }
};

//int main(){
//
//}