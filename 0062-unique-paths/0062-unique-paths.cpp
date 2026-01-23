class Solution {
public:
    int find(int row, int col, vector<vector<int>> &dp){
        if(row==0 || col==0){
            return dp[row][col] = 1;
        }else{
            if(dp[row][col]==0){
                return dp[row][col] = find(row-1,col,dp) + find(row, col-1,dp);
            }else{
                return dp[row][col];
            }
        }
    }
    int uniquePaths(int m, int n) {
        if(m==1||n==1) return 1;
        int count = 0;
        vector<vector<int>> dp(m, vector<int> (n,0));
        return find(m-1,n-1,dp);
    }
};