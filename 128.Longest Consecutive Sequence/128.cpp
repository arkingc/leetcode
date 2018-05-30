class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> map;
        
        int sz = nums.size(),res = 0;
        for(int i = 0;i < sz;i++){
            int idx = nums[i];
            if(map.find(idx) == map.end()){ //只处理没有处理过的数
                auto itr_l = map.find(idx - 1);
                auto itr_r = map.find(idx + 1);
                if(itr_l == map.end() && itr_r == map.end())//不与任何一个区间相连
                    map[idx] = 1;
                else if(itr_l != map.end() && itr_r != map.end()){//连接2个区间
                    int left = itr_l->second,right = itr_r->second;
                    map[idx - left] = left + right + 1;
                    map[idx + right] = left + right + 1;
                    map[idx] = left + right + 1;
                }
                else if(itr_l != map.end()){
                    int left = itr_l->second;
                    map[idx - left] = left + 1;
                    map[idx] = left + 1;
                }
                else{
                    int right = itr_r->second;
                    map[idx + right] = right + 1;
                    map[idx] = right + 1;
                }
                
                if(map[idx] > res)  res = map[idx];
            }
        }
        
        return res;
    }
};