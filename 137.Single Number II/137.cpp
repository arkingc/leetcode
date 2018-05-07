class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bits = sizeof(int) * 8;
        int pos = 1,res = 0;
        
        while(bits--){
            int sum = 0;
            for(int num : nums){
                sum += ((num & pos) == 0 ? 0 : 1);
            }
            if(sum % 3 == 1)    res |= pos;
            pos = pos << 1;
        }
        
        return res;
    }
};