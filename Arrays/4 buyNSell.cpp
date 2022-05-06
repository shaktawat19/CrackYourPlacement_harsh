https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    // Appr. 1: O(n*n)
     //Appr. 2: O(n)
       int minPrice = prices[0] , profit = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i] > minPrice){
               profit = max((prices[i] - minPrice),profit);
            }else{
                minPrice = prices[i];
            }
        }
        return profit;
    }
};
