class Solution {
public:
    int reverse(int x) {
        long long res = 0,num = x;
        bool negative = (num < 0);
        if(negative)    num *= -1;
        while(num){
            res = res * 10 + (num % 10);
            num = num / 10;
            if(res > INT_MAX){
                if(!negative)   return 0;
                if(res - 1 > INT_MAX)   return 0;
            }
        }
        if(negative)    res *= -1;
        return res;
    }
};