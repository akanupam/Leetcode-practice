class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int minutes = 0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            pair<int,int> it = q.front();
            q.pop();
            bool check = false;
            if(it.second>0 && grid[it.first][it.second-1]==1){
                grid[it.first][it.second-1] = 2;
                q.push({it.first,it.second-1});
                check = true;
            }
            if(it.second<m-1 && grid[it.first][it.second+1]==1){
                grid[it.first][it.second+1] = 2;
                q.push({it.first,it.second+1});
                check = true;
            }
            if(it.first>0 && grid[it.first-1][it.second]==1){
                grid[it.first-1][it.second] = 2;
                q.push({it.first-1,it.second});
                check = true;
            }
            if(it.first<n-1 && grid[it.first+1][it.second]==1){
                grid[it.first+1][it.second] = 2;
                q.push({it.first+1,it.second});
                check = true;
            }
            if(check) minutes++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return minutes;
    }
};