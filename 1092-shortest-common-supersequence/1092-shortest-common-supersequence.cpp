class Solution {
public:
    // string f(int ind1, int ind2, string& s1, string& s2, vector<vector<string>>& dp){
    //     if(ind1<0 && ind2<0){
    //         return "";
    //     }else if(ind1<0){
    //         return  s2.substr(0,ind2+1);
    //     }else if(ind2<0){
    //         return  s1.substr(0, ind1+1);
    //     }
    //     if(dp[ind1][ind2]!="-1") return dp[ind1][ind2];
    //     if(s1[ind1]==s2[ind2]){
    //         return dp[ind1][ind2] = f(ind1-1,ind2-1, s1, s2,dp) + s1[ind1];
    //     }else{
    //         string res1 = f(ind1-1,ind2,s1,s2,dp) +s1[ind1];
    //         string res2 = f(ind1, ind2-1, s1,s2,dp) +s2[ind2];
    //         if(res1.length() > res2.length()){
    //             return dp[ind1][ind2]= res2;
    //         }else{
    //             return dp[ind1][ind2] =res1;
    //         }
    //     }
    // }
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        int i= n;
        int j=m;
        string res = "";
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                res += str1[i-1];
                i--;
                j--;
            }else{
                if(dp[i-1][j] > dp[i][j-1]){
                    res+= str1[i-1];
                    i--;
                }else{
                    res += str2[j-1];
                    j--;
                }
            }
        }

        while(i>0){
            res+=str1[i-1];
            i--;
        }
        while(j>0){
            res+=str2[j-1];
            j--;
        }

        reverse(res.begin(),res.end());
        return res;
    }
};