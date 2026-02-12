class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // int n = asteroids.size();
        stack<int> st;
        // for(int i=n-1;i>=0;i++){
        //     int ele = asteroids[i];
        //     if(st.empty()){
        //         st.push(ele);
        //     }else{
        //         if(st.top() < 0){
        //             if(ele<0){
        //                 st.push(ele);
        //             }else{
        //                 while(!st.empty() && ele > -st.top()){
        //                     st.pop();
        //                 }
        //                 if(st.empty()) st.push(ele);
        //             }
        //         }else{
        //             if(ele>0){
        //                 st.push(ele);
        //             }else{
        //                 while(!st.empty() && -ele > st.top()){
        //                     st.pop();
        //                 }
        //                 if(st.empty()) st.push(ele);
        //             }
        //         }
        //     }
        // }
        for( int ele: asteroids){
            int flag = false;
            while(!st.empty() && st.top() > 0 && ele<0){
                if(st.top() < -ele){
                    st.pop();
                    continue;
                }else if(st.top() == -ele){
                    st.pop();
                    flag = true;
                    break;
                }else{
                    flag = true;
                    break;
                }
            }
            if(!flag){
                st.push(ele);
            }
        }
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};