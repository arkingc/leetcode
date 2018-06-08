class Solution {
public:
    int getSum(int a, int b) {
        int tp = (a & b) << 1;
        a = a ^ b,b = tp;
        while(b){
            tp = (a & b) << 1;
            a = a ^ b;
            b = tp;
        }
        return a;
    }
};