class Solution {
public:
    bool isIso(string s, string t){
        map<char,char> mpp;
        for(int i=0;i<s.length();i++){
            if(mpp.find(s[i])==mpp.end()){
                mpp[s[i]] = t[i];
            }else{
                if(mpp[s[i]]!=t[i]) return false;
            }
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        // vector<int> hashS(26,0);
        // vector<int> hashT(26,0);
        // for(int i=0;i<s.length();i++){
        //     hashS[s[i] -'a']++;
        //     hashT[t[i] -'a']++;
        // }
        // for(int i=0;i<s.length();i++){
        //     if(hashS[s[i] -'a'] != hashT[t[i] -'a']) return false;
        // }
        // return true;
        bool a = isIso(s,t);
        bool b = isIso(t,s);
        return a&&b;
    }
};