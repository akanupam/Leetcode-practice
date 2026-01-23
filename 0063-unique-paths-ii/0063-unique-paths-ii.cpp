class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] ==1 || obstacleGrid[m-1][n-1]==1) return 0;
        if(m==1 && n==1){
            if(obstacleGrid[0][0]==1){
                return 0;
            }else{
                return 1;
            }
        }
        if(m==1){
            for(int i=0;i<n;i++){
                if(obstacleGrid[0][i]==1){
                    return 0;
                }
            }
        }
        if(n==1){
            for(int i=0;i<m;i++){
                if(obstacleGrid[i][0]==1){
                    return 0;
                }
            }
        }
        vector<int> row(n,1);
        for(int i=1;i<n;i++){
            if(obstacleGrid[0][i] == 1){
                row[i] = 0;
            }else{
                row[i] = row[i-1];
            }
        }
        for(int i=1;i<m;i++){
            vector<int> temp = row;
            if(obstacleGrid[i][0]==1){
                temp[0] = 0;
            }
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j] == 1) {
                    temp[j] = 0;
                }else{
                    temp[j] = temp[j-1] + row[j];
                }
            }
            row= temp;
        }
        return row[n-1];
    }
};