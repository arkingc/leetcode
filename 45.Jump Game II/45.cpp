class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1)    return 0;
        
        int target = nums.size() - 1,res = 0;
        deque<int> d;
        d.push_back(0);
        vector<int> flags(nums.size(),0);   //防止重复添加节点
        flags[0] = 1;
        
        while(!d.empty()){
            int level = d.size();   //这一层的节点数
            while(level--){
                int src = d.front();
                d.pop_front();
                for(int i = nums[src];i >= 1;i--){
                    if(src + i >= target)        
                        return ++res;
                    else if(flags[src + i] == 1)
                        break;
                    else {
                        d.push_back(src + i);
                        flags[src + i] = 1;
                    }
                }
            }
            res++;
        }
        
        return -1;//无法到达
    }
};