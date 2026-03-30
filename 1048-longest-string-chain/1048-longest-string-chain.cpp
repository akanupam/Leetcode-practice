class Solution {
public:
    bool check(string& s1, string& s2){
        if(s2.length()!=s1.length()-1) return false;
        int j=0;
        int i=0;
        while(i<s1.length()){
            if(s1[i]==s2[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
        return j==s2.length();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n,1);
        sort(words.begin(), words.end(), [](string &a, string &b){
            return a.length() < b.length();
        });
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(words[i],words[j]) && dp[i]<dp[j]+1){
                    dp[i] = dp[j]+1;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};