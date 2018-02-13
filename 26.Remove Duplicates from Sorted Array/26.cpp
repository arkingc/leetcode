class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0,j = 0;
        while(++j < nums.size()){
            if(nums.at(j) != nums.at(i)){
                if(j - i > 1)
                    nums.at(i + 1) = nums.at(j);
                i++;
            }
        }
        return nums.size() == 0 ? 0 : i + 1;
    }
};