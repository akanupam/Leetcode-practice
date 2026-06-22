class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int n= height.size();
        int j=n-1;
        int maxArea=0;
        while(i<j){
            int len = min(height[i],height[j]);
            int wid = j-i;
            maxArea = max(maxArea, len*wid);
            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }
        }
        return maxArea;
    }
};