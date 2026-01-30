class Solution {
public:
    bool iso(string s,string t){
        map<int,int> mpp;
        if(s.length() != t.length()) return false;
        if(s.length() == 0 && t.length()==0){
            return true;
        }
        int a = s[0];
        int b = t[0];
        mpp[a] = b;
        for(int i=1;i<s.length();i++){
            int fst = s[i];
            int sec = t[i];
            if(mpp[fst] == 0){
                mpp[fst] = sec;
            }else{
                if(mpp[fst] != sec){
                    return false;
                }
            }
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        bool a = iso(s,t);
        bool b = iso(t,s);
        if(a && b){
            return true;
        }else{
            return false;
        }
        
        
        
        
        
        
        // for(int i =0;i<s.length();i++){
        //     int first = s[i];
        //     int second = t[i];
        //     mpp1[first]++;
        //     mpp2[second]++;
        // }
        // for(int i=0;i<s.length();i++){
        //     int first = s[i];
        //     int second = t[i];
        //     if(mpp1[first]!=mpp2[second]){
        //         return false;
        //     }
        // }
        // return true;

    }
};