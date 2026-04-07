class Solution {
public:
    bool isPalindrome(string str,int i, int j){
        while(i<j){
            if(str[i]!=str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int f(int i, string& s, int n, vector<int>& dp){
        if(i==n) return 0;
        int mini = INT_MAX;
        if(dp[i]!=-1){
            return dp[i];
        }
        for(int j=i;j<n;j++){
            if(isPalindrome(s,i,j)){
                int cost = 1 + f(j+1,s,n,dp);
                mini = min(mini,cost);
            }
        }
        return dp[i]=mini;
    }
    // int minCut(string s) {
    //     int n = s.length();
    //     vector<int> dp(n+1,0);
    //     dp[n]=0;
    //     // return f(0,s,n,dp) -1;
    //     for(int i=n-1;i>=0;i--){
    //         int mini = INT_MAX;
    //         for(int j=i;j<n;j++){
    //         if(isPalindrome(s,i,j)){
    //             int cost = 1 + dp[j+1];
    //             mini = min(mini,cost);
    //         }
    //     }
    //     dp[i] = mini;
    //     }
    //     return dp[0]-1;
    // }
    int minCut(string s) {
    int n = s.length();

    vector<vector<bool>> isPal(n, vector<bool>(n, false));

    // Precompute palindrome table
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (s[i] == s[j] && (j - i <= 2 || isPal[i+1][j-1])) {
                isPal[i][j] = true;
            }
        }
    }

    vector<int> dp(n + 1, 0);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--) {
        int mini = INT_MAX;
        for (int j = i; j < n; j++) {
            if (isPal[i][j]) {
                mini = min(mini, 1 + dp[j + 1]);
            }
        }
        dp[i] = mini;
    }

    return dp[0] - 1;
}
};