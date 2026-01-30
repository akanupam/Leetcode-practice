class Solution {
public:
    bool palindrome(string s, int l, int r){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }else{
                l++;
                r--;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.length() -1;
        while(l<r){
            if(s[l]==s[r]){
                l++;
                r--;
            }else{
                if(palindrome(s,l,r-1)||palindrome(s,l+1,r)){
                    return true;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};