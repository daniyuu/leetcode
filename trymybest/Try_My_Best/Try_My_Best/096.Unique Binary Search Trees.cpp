/* Dynamic programming 
 
 ### **分析**：
 
 DP 公式为：
 `dp[i] = dp[k] * dp[i-k-1] { 0<=k<=i-1 }`
 可以这样理解：
 求 {1, 2, ...., i} 的 BST，我们拿其中的一个数作根（假设为 k），根据 BST 的特性，左子树就是 {1, 2, ..., k-1}，右子树就是 {k+1, k+2, ..., i} 了。
 而很明显 {k+1, k+2, ..., i} 化 BST 的可能性和 {1, 2, ..., i-(k+1)} 是一样的。
 记 {1, 2, ..., n} 的 BST 个数为 f(n)，上述就可以表达为 `f(i) = f(k-1) * f(i-k-1)`。
 而我们选择的 k 就是 {1, 2, ...., i} 中的任意一个，而不同的 k 等到的 BST 是不会重复的。

 
 如果集合为空，只有一种BST，即空树，
 
 UniqueTrees[0] =1
 
 如果集合仅有一个元素，只有一种BST，即为单个节点UniqueTrees[1] = 1
 
 UniqueTrees[2] = UniqueTrees[0] * UniqueTrees[1]   (1为根的情况)+ UniqueTrees[1] * UniqueTrees[0]  (2为根的情况。
 
 再看一遍三个元素的数组，可以发现BST的取值方式如下：
 
 UniqueTrees[3] = UniqueTrees[0]*UniqueTrees[2]  (1为根的情况)
 
 + UniqueTrees[1]*UniqueTrees[1]  (2为根的情况)
 
 + UniqueTrees[2]*UniqueTrees[0]  (3为根的情况)
 
 所以，由此观察，可以得出UniqueTrees的递推公式为UniqueTrees[i] = ∑ UniqueTrees[0...k] * [i-1-k]     k取值范围 0<= k <=(i-1)
 
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int numTrees(int n){
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int k = 0; k < i; ++k) {
                dp[i] += dp[k] * dp[i - k - 1];
            }
        }
        
        return dp[n];
    }
};