class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();

        vector<vector<vector<int>>> dp(n,
            vector<vector<int>>(m, vector<int>(3, -1e9)));

        for(int d = 0; d <= 2; d++){
            if(coins[0][0] < 0 && d > 0)
                dp[0][0][d] = max(0, coins[0][0]);
            else
                dp[0][0][d] = coins[0][0];
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0) continue;

                for(int d = 0; d <= 2; d++){
                    int val = coins[i][j];

                    int best = -1e9;
                    if(i > 0){
                        if(val < 0){
                            int take = val + dp[i-1][j][d];
                            int skip = (d > 0) ? dp[i-1][j][d-1] : -1e9;
                            best = max(best, max(take, skip));
                        } else {
                            best = max(best, val + dp[i-1][j][d]);
                        }
                    }
                    if(j > 0){
                        if(val < 0){
                            int take = val + dp[i][j-1][d];
                            int skip = (d > 0) ? dp[i][j-1][d-1] : -1e9;
                            best = max(best, max(take, skip));
                        } else {
                            best = max(best, val + dp[i][j-1][d]);
                        }
                    }

                    dp[i][j][d] = best;
                }
            }
        }

        return dp[n-1][m-1][2];
    }
};