class Solution {
public:
    void dfs(string& num, int target, int start, long long current_value, long long last_operand, string expression, vector<string>& res){
        if(start==num.size()){
            if(current_value==target){
                res.push_back(expression);
            }
            return;
        }
        for(int i=start; i<num.size();i++){
            if(i>start && num[start]=='0') return;
            string current_num = num.substr(start, i-start+1);
            long long current_num_val = stoll(current_num);
            if(start==0){
                dfs(num, target, i+1, current_num_val, current_num_val, current_num, res);
            }else{
                dfs(num, target, i+1,current_value + current_num_val, current_num_val,expression + "+" + current_num, res);
                dfs(num, target, i+1,current_value - current_num_val, -current_num_val, expression + "-" + current_num, res);
                dfs(num, target, i+1,current_value - last_operand + last_operand * current_num_val, last_operand*current_num_val, expression + "*" + current_num, res);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        dfs(num, target, 0,0,0, "", res);
        return res;
    }
};