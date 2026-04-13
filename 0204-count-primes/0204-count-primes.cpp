class Solution {
public:
    int countPrimes(int n) {
        vector<int> isPrime(n+1,true);
        if(n==0||n==1||n==2) return 0;
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i=2;i*i<=n;i++){
            if(isPrime[i]){
                for(int j=2;j*i<=n;j++){
                    isPrime[j*i]=false;
                }
            }
        }
        int c=0;
        for(int i=2;i<n;i++){
            if(isPrime[i]) c++;
        }
        return c;
    }
};