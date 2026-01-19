class Solution {
public:
    // void f(int a, int& c, int& n){
    //     if(a>n){
    //         return;
    //     }
    //     if(a==n){
    //         c++;
    //         return;
    //     }
    //     f(a+1, c, n);
    //     f(a+2, c, n);
    // }
    int climbStairs(int n) {
        int prev = 2;
        int prev2 = 1;
        int count = 0;
        if(n<=2){
            return n;
        }
        for(int i=3;i<=n;i++){
            count = prev + prev2;
            prev2 = prev;
            prev = count;
        }
        return count;
    }
};