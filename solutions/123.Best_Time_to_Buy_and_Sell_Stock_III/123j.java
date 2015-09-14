public class Solution {
    public int maxProfit(int[] prices) {
    	int n = prices.length;
    	if(n == 0){
    		return 0;
    	}
    	int profit = 0;
    	int buy_price = prices[0];

    	int[] left = new int[n];

    	for(int i = 1; i < n; ++i){
    		buy_price = Math.min(buy_price ,prices[i]);
    		profit = Math.max(profit, prices[i] - buy_price);
    		left[i] = profit;
    	}

    	int res = 0;
    	buy_price = prices[n - 1];
    	profit = 0;

    	for(int i = n - 1; i > 0; --i){
    		buy_price = Math.max(buy_price, prices[i]);
    		profit = Math.max(profit, buy_price - prices[i]);
    		res = Math.max(res, profit + left[i]);
    	}

    	return res;
        
    }
}