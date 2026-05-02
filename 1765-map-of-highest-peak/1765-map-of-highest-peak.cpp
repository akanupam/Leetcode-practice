class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> res(n, vector<int>(m,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    res[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        vector<int> dr = {1,-1,0,0};
        vector<int> dc = {0,0,1,-1};
        while(!q.empty()){
            auto[r,c] = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >=0 && nc >=0 && nr < n && nc < m && res[nr][nc]==-1){
                    res[nr][nc] = res[r][c] +1;
                    q.push({nr,nc});
                }
            }
        }
        return res;
    }
};