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
        int ans = INT_MAX;
        vector<vector<int>> dp;
        for(int i=0;i<=level;i++){
            vector<int> temp(i+1,-1);
            dp.push_back(temp);
        }
        for(int i=0;i<=level;i++){
            int sum = 0;
            sum = fetch(i,level,triangle,sum,dp);
            ans = min(sum,ans);
        }
        return ans;
    }
};