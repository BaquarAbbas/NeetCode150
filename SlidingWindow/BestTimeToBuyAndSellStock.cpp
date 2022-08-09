/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/
//Time:O(N) where N is the size of prices vector.
//Space:O(1)
//Solution1

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0,right = 1;
        int profit = 0;
        while(right < prices.size()){
            if(prices[left] < prices[right]){
                profit = max(profit,prices[right] - prices[left]);
            }
            else{
                left = right;
            }
            right++;
        }
        return profit;
    }
};
