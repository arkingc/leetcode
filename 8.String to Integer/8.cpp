class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        //找到第一个不为' '的位置
        for(;i < str.length() && str[i] == ' ';i++) ;
        if(i >= str.length())   return 0;
        
        bool negative = (str[i] == '-');
        if(str[i] == '+' || str[i] == '-') i++;
        
        long long res = 0;
        for(;i < str.length();i++){
            if(str[i] > '9' || str[i] < '0')    break;
            res = res * 10 + (str[i] - '0');
            if(res > INT_MAX){
                if(!negative)   return INT_MAX;
                if(res - 1 > INT_MAX)   return INT_MIN;
            }
        }
        
        if(negative)    res *= -1;
        return (int)res;
    }
};