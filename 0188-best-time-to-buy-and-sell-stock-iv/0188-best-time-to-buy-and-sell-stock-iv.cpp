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
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1,0)));
        // return f(prices,0,1,k,n,dp);
        vector<vector<int>> next(2, vector<int>(k+1, 0));
        for(int i=n-1;i>=0;i--){
            vector<vector<int>> curr(2, vector<int>(k+1, 0));
            for(int j=0;j<2;j++){
                for(int l=1;l<=k;l++){
                    int profit;
                    if(j==1){
                        profit = max(-prices[i] + next[0][l], next[1][l]);
                    }
                    if(j==0){
                        profit = max(prices[i] + next[1][l-1], next[0][l]);
                    }
                    curr[j][l] = profit;
                }
            }
            next = curr;
        }
        return next[1][k];
    }
};