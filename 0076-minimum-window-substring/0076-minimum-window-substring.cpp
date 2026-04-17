class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        int cnt = 0;
        int sInd = -1;
        int minlen = INT_MAX;
        map<char,int> mpp;
        for(int i = 0; i < m; i++) {
            mpp[t[i]]++;
        }
        int i = 0, j = 0;
        while(j < n) {
            if(mpp[s[j]] > 0) {
                cnt++;
            }
            mpp[s[j]]--;
            while(cnt == m) {
                if(j - i + 1 < minlen) {
                    minlen = j - i + 1;
                    sInd = i;
                }
                mpp[s[i]]++;
                if(mpp[s[i]] > 0) {
                    cnt--;
                }
                i++;
            }
            j++;
        }
        return sInd == -1 ? "" : s.substr(sInd, minlen);
    }
};