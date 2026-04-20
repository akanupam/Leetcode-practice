class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<int> st;
        for(int i=0;i<=n;i++){
            // int minHeight = INT_MAX;
            // for(int j=i;j<n;j++){
            //     minHeight = min(minHeight, heights[j]);
            //     int width = j-i+1;
            //     int area = width * minHeight;
            //     maxArea = max(area,maxArea);
            // }
            while(!st.empty() && (i==n || heights[st.top()]>= heights[i])){
                int height = heights[st.top()];
                int width;
                st.pop();
                if(st.empty()){
                    width = i;
                }else{
                    width = i- st.top() -1;
                }
                maxArea= max(maxArea, width*height);
            }
            st.push(i);
        }

        return maxArea;
    }
};