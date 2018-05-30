class Solution {
public:
    int mySqrt(int x) {
        if(x < 0 || x == 0)   return 0;
        
        int l = 1,r = INT_MAX;
        while(true){
            int mid = l + ((r - l) >> 1);
            if(mid > x / mid)  //mid * mid > x，继续往左边找
                r = mid - 1;
            else{ //mid * mid <= x
                if(mid + 1 > x / (mid + 1)) 
                    return mid;
                l = mid + 1;
            }
        }
    }
};