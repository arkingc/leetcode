class Solution {
public:
    int trailingZeroes(int n) {
        long long num = 5;
        int count = 0;
        while(num <= n){
            count += (n / num);
            num *= 5;
        }
        return count;
    }
};