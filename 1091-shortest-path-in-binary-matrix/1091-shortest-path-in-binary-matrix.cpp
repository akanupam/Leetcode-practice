class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        // int V = n*n;
        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        queue<pair<int,int>> q;
        dist[0][0]=1;
        q.push({0,0});
        vector<int> dr = {-1,-1,-1,0,0,1,1,1};
        vector<int> dc = {-1,0,1,-1,1,-1,0,1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;
            
            for(int i=0;i<8;i++){
                int pr = dr[i]+r;
                int pc = dc[i]+c;
                if(pr >= 0 && pr<n && pc>=0 && pc <n && grid[pr][pc]==0 && dist[pr][pc]==INT_MAX){
                    dist[pr][pc]=dist[r][c] + 1;
                    q.push({pr,pc});
                }
            }
        }
        return dist[n-1][n-1]==INT_MAX?-1:dist[n-1][n-1];
    }
};