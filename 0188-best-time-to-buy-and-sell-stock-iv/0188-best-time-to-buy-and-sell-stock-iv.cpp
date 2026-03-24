class Solution {
public:
    int f(vector<int>& prices, int ind, int buy, int k, int n,vector<vector<vector<int>>> &dp ){
        if(k<=0||ind>=n){
            return 0;
        }
        if(dp[ind][buy][k]!=-1) return dp[ind][buy][k];
        int profit;
        if(buy==1){
            profit = max(-prices[ind] + f(prices, ind+1,0,k,n,dp), f(prices,ind+1, 1, k,n,dp));
        }else{
            profit = max(prices[ind] + f(prices, ind+1, 1, k-1, n,dp), f(prices, ind+1,0, k, n,dp));
        }
        return dp[ind][buy][k] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1,-1)));
        return f(prices,0,1,k,n,dp);
    }
};