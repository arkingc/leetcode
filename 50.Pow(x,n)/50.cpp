class Solution {
public:
    double myPow(double x, int n) {
        bool b = n < 0;
        
        if(x == 0)  return 0;
        if(n == 0)  return 1;
        
        //需要使用一个long long类型的变量，因为当n为INT_MIN时，和-1乘会溢出
        long long nl = n < 0 ? (long long)n * -1 : n;
        double ret = 1.0;
        
        while(nl){
            long long m = 1;//m必须也是long long,因为当m = INT_MAX/2+1时，计算m*2会溢出
            double tp = x;
            while(2 * m <= nl){
                tp *= tp;
                m *= 2;
            }
            nl = nl - m;
            ret *= tp;
        }
        
        ret = b ? 1 / ret : ret;
        return ret;
    }
};