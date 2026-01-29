class Solution {
public:
    int findMin(vector<vector<int>>& matrix, int row,int col, int sum, int n, vector<vector<int>>& dp){
        if(row==0){
            return dp[row][col] = matrix[row][col];
        }
        if(dp[row][col]==-101){
            if(col==0){
                sum=matrix[row][col] + min(findMin(matrix,row-1,col,sum,n,dp),findMin(matrix,row-1,col+1,sum,n,dp));
                dp[row][col] = sum;
            }else if(col==n-1){
                sum= matrix[row][col] + min(findMin(matrix,row-1,col-1,sum,n,dp),findMin(matrix,row-1,col,sum,n,dp));
                dp[row][col] = sum;
            }else{
                sum= matrix[row][col] +  min(findMin(matrix,row-1,col-1,sum,n,dp), min(findMin(matrix,row-1,col,sum,n,dp),findMin(matrix,row-1,col+1,sum,n,dp)));
                dp[row][col] = sum;
            }
        }else{
            return dp[row][col];
        }
        return dp[row][col] = sum;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,-101));
        for(int i=0;i<n;i++){
            int sum = 0;
            sum = findMin(matrix,n-1,i,sum,n,dp);
            ans = min(ans,sum);
        }
        return ans;
    }
};