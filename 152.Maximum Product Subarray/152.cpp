class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty())    return 0;
        
        int max_global = nums[0];
        int max_local = nums[0],min_local = nums[0];
        
        for(int i = 1;i < nums.size();i++){
            int _max = max(max_local * nums[i],min_local * nums[i],nums[i]);
            int _min = min(max_local * nums[i],min_local * nums[i],nums[i]);
            max_local = _max;
            min_local = _min;
            if(max_local > max_global)  max_global = max_local;
        }
        
        return max_global;
    }
private:
    int max(int num1,int num2,int num3){
        return num1 > num2 ? (num1 > num3 ? num1 : num3) : (num2 > num3 ? num2 : num3); 
    }
    
    int min(int num1,int num2,int num3){
        return num1 < num2 ? (num1 < num3 ? num1 : num3) : (num2 < num3 ? num2 : num3);
    }
};