class Solution {
public:
    int maxProfit(vector<int>& prices) {
  		if(prices.size() == 0){
  			return 0;
  		}     

  		vector<int> left(prices.size());
  		int buy_price = prices[0];
  		int profit = 0;

  		for(int i = 1; i < prices.size(); ++i){
  			buy_price = min(buy_price, prices[i]);
  			profit = max(profit, prices[i] - buy_price);
  			left[i] = profit;
  		}

  		int res = 0;
  		buy_price = prices[prices.size() - 1];
  		profit = 0;

  		for(int i = prices.size() - 1; i > 0; --i){
  			buy_price = max(buy_price, prices[i]);
  			profit = max(profit, buy_price - prices[i]);
  			res = max(res, profit + left[i]);
  		}

  		return res;
    }
};