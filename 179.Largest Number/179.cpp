class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](const int &num1,const int &num2){
            return to_string(num2) + to_string(num1) < to_string(num1) + to_string(num2);
        });
        
        //处理所有元素都是0的情况
        if(!nums.empty() && nums[0] == 0)   return "0";
        
        string res = "";
        for(int num : nums) res = res + to_string(num);
        
        return res;
    }
};