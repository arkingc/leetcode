class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        //srand(time(0));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(map.find(val) != map.end())  return false;
        nums.emplace_back(val);
        map[val] = nums.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(map.find(val) == map.end())  return false;
        int idxOfval = map[val];
        int last = nums.back();
        nums[idxOfval] = last;
        map[last] = idxOfval;
        map.erase(val);
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
private:
    vector<int> nums;               //存储元素
    unordered_map<int,int> map;     //存储元素在nums中的下标
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */