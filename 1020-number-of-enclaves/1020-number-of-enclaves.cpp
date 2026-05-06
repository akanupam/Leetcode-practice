class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                q.push({i,0});
                grid[i][0]=0;
            }
            if(grid[i][m-1]==1){
                q.push({i,m-1});
                grid[i][m-1]=0;
            }
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]==1){
                q.push({0,i});
                grid[0][i]=0;
            }
            if(grid[n-1][i]==1){
                q.push({n-1,i});
                grid[n-1][i]=0;
            }
        }
        while(!q.empty()){
            auto[r,c] = q.front();
            q.pop();

            vector<int> dr = {1,-1,0,0};
            vector<int> dc = {0,0,-1,1};

            for(int i=0;i<4;i++){
                int sr = dr[i] + r;
                int sc = dc[i] + c;
                if(sr > 0 && sc > 0 && sr<n && sc< m && grid[sr][sc]==1){
                    q.push({sr,sc});
                    grid[sr][sc]=0;
                }
            }

        }
        int c=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==1){
                    c++;
                }
            }
        }
        return c;
    }
};