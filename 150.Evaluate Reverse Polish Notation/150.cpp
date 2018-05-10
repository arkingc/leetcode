class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for(const string &s : tokens){
            if(s == "+"){
                int num = nums.top();
                nums.pop();
                nums.top() = nums.top() + num;
            }
            else if(s == "-"){
                int num = nums.top();
                nums.pop();
                nums.top() = nums.top() - num;
            }
            else if(s == "*"){
                int num = nums.top();
                nums.pop();
                nums.top() = nums.top() * num;
            }
            else if(s == "/"){
                int num = nums.top();
                nums.pop();
                nums.top() = nums.top() / num;
            }
            else{
                nums.push(stoi(s));
            }
        }
        return nums.top();
    }
};