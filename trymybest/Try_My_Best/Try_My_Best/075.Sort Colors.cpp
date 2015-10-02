#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = {0};
        
        for (int i = 0; i < nums.size(); ++i) {
            count[nums[i]]++;
        }
        
        for (int i = 0, index = 0; i < 3; ++i) {
            for (int j = 0; j < count[i]; ++j) {
                nums[index++] = i;
            }
        }
    }
    
};