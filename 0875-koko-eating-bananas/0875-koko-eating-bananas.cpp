class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // int l= 0;
        // int n = piles.size();
        // int r = n-1;
        // int nhep = h/n;
        // int sl,sm,sr;
        // while(l<r){
        //     int mid = l + (r-l)/2;
        //     sl = piles[l]/nhep;
        //     sr = piles[r]/nhep;
        //     sm = piles[mid]/nhep;
        //     if(sm <= sr){
        //         l = mid+1;
        //     }else{
        //         r = mid-1;
        //     }
        // }
        // return sm;
        int l = 0;
        int r = 0;
        long long sum = 0;
        for(int i=0;i<piles.size();i++){
            sum += piles[i];
            r = max(r,piles[i]);
        }
        l = sum/h;
        if(l==0){
            l=1;
        }
        int ans = 0;
        while(l<=r){
            int mid = l + (r-l)/2;
            int total = 0;
            for(int i=0;i<piles.size();i++){
                total += piles[i]/mid;
                if(piles[i]%mid){
                    total++;
                }
            }
            if(total > h){
                l = mid +1;;
            }else{
                ans = mid;
                r = mid-1;
            }
        }
        return ans; 
    }
};