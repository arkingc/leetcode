class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //统计每个元素出现的次数
        unordered_map<int,int> map;
        for(int num : nums)
            map[num]++;
        
        //桶的下标表示元素出现的次数,所以下标越大出现越频繁
        vector<vector<int>> bucket(nums.size() + 1);
        for(auto p : map)
            bucket[p.second].push_back(p.first);
        
        vector<int> res;
        //从后面的桶往前面遍历
        for(int i = bucket.size() - 1;i >= 0 && res.size() < k;--i){
            //遍历桶中的每个数
            for(int num : bucket[i]){
                res.push_back(num);
                if(res.size() == k)
                    break;
            }
        }
        
        return res;
    }
};