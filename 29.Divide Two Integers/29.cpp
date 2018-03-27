class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0 || dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        bool negative = !((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0));
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        
        long long res = 0 ;
        while(dvd >= dvs){
            long long tp = dvs;
            long long count = 1;
            while(dvd >= (tp << 1)){
                count <<= 1;
                tp <<= 1;
            }
            res += count;
            dvd -= tp;
        }
        
        res = negative ? res * -1 : res;
        return res;
    }
};