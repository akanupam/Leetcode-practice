class Solution {
public:
    int fetch(int index, int level,vector<vector<int>>& triangle , int sum, vector<vector<int>>& dp){
        if(level==0){
            return dp[0][0] = triangle[0][0];
        }else{
            if(dp[level][index]==-1){
            sum = triangle[level][index];
            if(index==0){
                sum += fetch(index, level-1, triangle, sum,dp);
                dp[level][index] = sum;
            }else if(index == level){
                sum  += fetch(index-1,level-1, triangle,sum,dp);
                dp[level][index] = sum;
            }else{
                sum += min(fetch(index, level-1, triangle, sum,dp),fetch(index-1,level-1, triangle,sum,dp));
                dp[level][index] = sum;
            }}else{
                return dp[level][index];
            }
        }
        return sum;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int level = triangle.size() -1;
        // int ans = INT_MAX;
        //Tabulation:
        // vector<vector<int>> dp;
        // for(int i=0;i<=level;i++){
        //     vector<int> temp(i+1,-1);
        //     dp.push_back(temp);
        // }
        // dp[0][0] = triangle[0][0];
        // for(int i=1;i<=level;i++){
        //     dp[i][0] = dp[i-1][0] + triangle[i][0];
        // }
        // for(int i=1;i<=level;i++){
        //     dp[i][i] = dp[i-1][i-1] + triangle[i][i];
        // }

        // for(int i=1;i<=level;i++){
        //     for(int j=1;j<triangle[i].size()-1;j++){
        //         dp[i][j] = triangle[i][j] + min(dp[i-1][j],dp[i-1][j-1]);
        //     }
        // }
        // for(int i=0;i<triangle[level].size();i++){
        //     ans = min(dp[level][i],ans);
        // }

        //Space Optimized Tabulation
        // vector<int> dp = triangle[0];
        for(int i=1;i<=level;i++){
            // vector<int> temp;
            for(int j=0;j<triangle[i].size();j++){
                // if(j==0){
                //     temp.push_back(triangle[i][j] + triangle[i-1][j]);
                // }else if(j==i){
                //     temp.push_back(triangle[i][j] + triangle[i-1][j-1]);
                // }else{
                //     temp.push_back(triangle[i][j] + min(triangle[i-1][j],triangle[i-1][j-1]));
                // }
                if(j==0){
                    triangle[i][j] = triangle[i][j] + triangle[i-1][j];
                }else if(j==i){
                    triangle[i][j] = triangle[i][j] + triangle[i-1][j-1];
                }else{
                    triangle[i][j] = triangle[i][j] + min(triangle[i-1][j],triangle[i-1][j-1]);
                }
            }
            // triangle[i] = temp;
        }
        for(int i=1;i<triangle[level].size();i++){
            triangle[level][i] = min(triangle[level][i],triangle[level][i-1]);
        }



        //Memoization in Recurrsion
        // for(int i=0;i<=level;i++){
        //     int sum = 0;
        //     sum = fetch(i,level,triangle,sum,dp);
        //     ans = min(sum,ans);
        // }
        return triangle[level][level];
    }
};