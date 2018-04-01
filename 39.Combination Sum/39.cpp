class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.size() == 0)  return vector<vector<int>>();

        std::sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> set;
        combinationSum(candidates,target,0,res,set);

        return res;
    }
private:
    void combinationSum(const vector<int> &candidates,int target,int idx,vector<vector<int>> &res,vector<int> &set){
        if(idx == candidates.size()){
            if(!target)   res.push_back(set);
            return;
        }

        if(target >= candidates[idx]){
            combinationSum(candidates,target,idx + 1,res,set);
            set.push_back(candidates[idx]);
            combinationSum(candidates,target - candidates[idx],idx,res,set);
            set.pop_back();
        }
    }
};