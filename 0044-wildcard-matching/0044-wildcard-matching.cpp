class Solution {
public:
    bool f(int i, int j, string& s, string& p, vector<vector<int>>& dp){
        if(i<0 && j<0) return true;
        if(j<0) return false;

        if(i<0){
            for(int k = 0; k <= j; k++){
                if(p[k] != '*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j]||p[j]=='?'){
            return dp[i][j] = f(i-1,j-1,s,p,dp);
        }
        if (p[j]=='*'){
            return dp[i][j] = f(i-1,j,s,p,dp)||f(i,j-1,s,p,dp);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        vector<bool> prev(m+1, false);
        prev[0] = true;
        for(int i=1;i<=m;i++){
            if(p[i-1] == '*')
                prev[i] = prev[i-1];
        }

        for(int i=1;i<=n;i++){
            vector<bool> curr(m+1, false);
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1]||p[j-1]=='?'){
                    curr[j] = prev[j-1];
                }else if(p[j-1]=='*'){
                    curr[j] = prev[j]||curr[j-1];
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};