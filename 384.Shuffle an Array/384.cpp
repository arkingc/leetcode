class Solution {
public:
    Solution(vector<int> nums) : _nums(nums) {
        srand(time(0));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return _nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res = _nums;
        
        for(int i = res.size() - 1;i >= 1;i--){
            int random = rand() % (i + 1);
            int tp = res[i];
            res[i] = res[random];
            res[random] = tp;
        }
        
        return res;
    }
private:
    vector<int> _nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */


class Solution {
public:
    Solution(vector<int> nums) : _nums(nums) , reserve(nums) {
        srand(time(0));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        _nums = reserve;
        return _nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int i = _nums.size() - 1;i >= 1;i--){
            int random = rand() % (i + 1);
            int tp = _nums[i];
            _nums[i] = _nums[random];
            _nums[random] = tp;
        }
        
        return _nums;
    }
private:
    vector<int> _nums;
    vector<int> reserve;
};