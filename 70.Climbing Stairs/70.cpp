class Solution {
public:
    int climbStairs(int n) {
        if(n <= 0)  return 0;
        if(n == 1)  return 1;
        if(n == 2)  return 2;
        
        int count1 = 1,count2 = 2,count;   
        for(int i = 3;i <= n;i++){
            count = count1 + count2;
            count1 = count2;
            count2 = count;
        }
        
        return count;
    }
};