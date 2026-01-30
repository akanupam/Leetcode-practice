class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> hash(26,0);
        if(s.length()!=t.length()) return false;
        for(int i=0;i<s.length();i++){
            char c = s[i];
            hash[c-'a']++;
        }
        for(int i=0;i<t.length();i++){
            char c = t[i];
            if(hash[c-'a']<=0){
                return false;
            }else{
                hash[c-'a']--;
            }
        }
        return true;
    }
};