class Solution {
public:
    int find(int row, int col){
        if(row==0 || col==0){
            return 1;
        }else{
            return find(row-1,col) + find(row, col-1);
        }
    }
    int uniquePaths(int m, int n) {
        if(m==1||n==1) return 1;
        int count = 0;
        
        return find(m-1,n-1);
    }
};