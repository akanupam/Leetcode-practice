class Solution {
public:
    int f(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp, int maxi){
        if(row==0 && col == 0){
            return dp[row][col] = grid[row][col] + maxi;
        }
        if(dp[row][col] == -1){
            if(row==0){
                maxi = f(row,col-1,grid,dp,maxi) + grid[row][col];
                return dp[row][col]  = maxi;
            }
            if(col==0){
                maxi = f(row -1,col,grid,dp,maxi) + grid[row][col];
                return dp[row][col]  = maxi;
            }
            maxi = min(f(row,col-1,grid,dp,maxi),f(row -1,col,grid,dp,maxi)) + grid[row][col];
            return dp[row][col] = maxi;
        }else{
            return dp[row][col];
        }
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        int maxi = 0;
        return f(m-1,n-1,grid,dp,maxi);
    }
};