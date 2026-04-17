class Solution {
public:
    int numberOfSubstrings(string s) {
        int n= s.length();
        int cnt= 0;
        vector<int> hash(3,0);
        int i=0;
        for(int j=0;j<n;j++){
            hash[s[j]-'a']++;
            while(hash[0]!=0 && hash[1]!=0 && hash[2]!=0){
                cnt+= n-j;
                hash[s[i]- 'a']--;
                i++;
            }
        }
        return cnt;
    }
};