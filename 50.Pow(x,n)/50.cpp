class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0)  return 0;
        if(n == 0)  return 1;
        
        long long nl = n;
        bool negative = nl < 0;
        if(negative)    nl = nl * -1;
        
        while((nl & 1) == 0){
            nl >>= 1;
            x *= x;
        }
        
        double res = x;
        nl >>= 1;
        
        while(nl){
            x *= x;
            if((nl & 1) == 1) res *= x;
            nl >>= 1;
        }
        
        if(negative)    return 1 / res;
        return res;
    }
};