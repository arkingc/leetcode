class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int sz = nums.size();
        
        if(sz == 0) return 0; 
        
        int maxGlobal = nums[0],maxLocal = nums[0],minLocal = nums[0];
        int tp1,tp2;

        for(int i = 1;i < sz;i++){
            tp1 = max(maxLocal * nums[i],minLocal * nums[i],nums[i]);
            tp2 = min(maxLocal * nums[i],minLocal * nums[i],nums[i]);
            maxLocal = tp1,minLocal = tp2;
            if(maxGlobal < maxLocal)    maxGlobal = maxLocal;
        }
        
        return maxGlobal;
    }
private:
    int max(const int &v1,const int &v2,const int &v3){
        return v1 >= v2 ? (v1 >= v3 ? v1 : v3) : (v2 >= v3 ? v2 : v3);    
    }
    int min(const int &v1,const int &v2,const int &v3){
        return v1 <= v2 ? (v1 <= v3 ? v1 : v3) : (v2 <= v3 ? v2 : v3);
    }
};