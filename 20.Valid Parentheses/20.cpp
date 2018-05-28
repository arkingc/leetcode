class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(int i = 0;i < s.length();i++){
            switch(s[i]){
                case ')':
                    if(stack.empty() || stack.top() != '(')
                        return false;
                    stack.pop();
                    break;
                case '}':
                    if(stack.empty() || stack.top() != '{')
                        return false;
                    stack.pop();
                    break;
                case ']':
                    if(stack.empty() || stack.top() != '[')
                        return false;
                    stack.pop();
                    break;
                default:
                    stack.push(s[i]);
                    break;
            }
        }
        return stack.empty() ? true : false;
    }
};