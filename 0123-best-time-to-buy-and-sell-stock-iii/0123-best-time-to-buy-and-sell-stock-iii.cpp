class Solution {
public:
    int f(vector<int>& prices, int ind, int buy, int c, int n, vector<vector<vector<int>>>& dp){
        if(ind == n|| c>1){
            return 0;
        }
        if(dp[ind][buy][c]!=-1) return dp[ind][buy][c];
        int profit;
        if(buy){
            profit = max(-prices[ind] + f(prices,ind+1,0,c,n,dp), f(prices, ind+1,1,c,n,dp));
        }else{
            profit = max(prices[ind] + f(prices,ind+1,1,c+1,n,dp), f(prices,ind+1,0,c,n,dp));
        }
        return dp[ind][buy][c] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2,-1)));
        return f(prices, 0, 1, 0, n, dp);
    }
};