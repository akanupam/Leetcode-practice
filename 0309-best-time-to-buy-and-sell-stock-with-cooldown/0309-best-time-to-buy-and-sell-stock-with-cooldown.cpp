class Solution {
public:
    int f(vector<int>& prices, int ind, int buy, int n, vector<vector<int>> &dp){
        if(ind>=n){
            return 0;
        }
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit;
        if(buy==1){
            profit = max(-prices[ind] + f(prices, ind+1,0,n,dp), f(prices,ind+1, 1,n,dp));
        }else{
            profit = max(prices[ind] + f(prices, ind+2, 1, n,dp), f(prices, ind+1,0, n,dp));
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(prices,0,1,n,dp);
    }
};