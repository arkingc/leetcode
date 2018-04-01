class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> set;
        
        sort(candidates.begin(),candidates.end());
        
        combinationSum2(candidates,target,res,set,0);
        
        return res;
    }

private:
    void combinationSum2(vector<int> &candidates,int target,vector<vector<int>> &res,vector<int> &set,int idx){
        if(target == 0){
            res.push_back(set);
            return;
        }
        
        for(int i = idx;i < candidates.size() && target >= candidates[i];++i){
            //if(i != idx && candidates[i] == candidates[i - 1])  continue;
            if(i == idx || candidates[i] != candidates[i - 1]){
                set.push_back(candidates[i]);
                combinationSum2(candidates,target - candidates[i],res,set,i + 1);
                set.pop_back();
            }
        }
    }
};