class Solution {
public:
    void dfs(vector<vector<bool>>& visited,int i, int j, vector<vector<char>>& board){
        if(i>=board.size()||j>=board[0].size()||i<0||j<0||board[i][j]=='X'||visited[i][j]){
            return;
        }
        visited[i][j] = true;
        dfs(visited, i+1,j,board);
        dfs(visited, i-1,j,board);
        dfs(visited, i,j+1,board);
        dfs(visited, i,j-1,board);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                dfs(visited, 0,i,board);
            }
            if(board[n-1][i]=='O'){
                dfs(visited, n-1,i,board);
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                dfs(visited, i,0,board);
            }
            if(board[i][m-1]=='O'){
                dfs(visited, i,m-1,board);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'O' && visited[i][j]==false){
                    board[i][j] = 'X';
                }
            }
        }
    }
};