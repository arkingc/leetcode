class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> idx;
        for(int i = 0;i < nums.size();i++)  idx.push_back(i);
        vector<int> res(nums.size(),0);
        vector<int> tmp(nums.size(),0);
        countSmallerCore(nums,idx,tmp,res,0,nums.size() - 1);
        return res;
    }
private:
    void countSmallerCore(vector<int> &nums,vector<int> &idx,vector<int> &tmp,vector<int> &res,int l,int r){
        if(l >= r)  return;

        int mid = (l + r) >> 1;
        countSmallerCore(nums,idx,tmp,res,l,mid);
        countSmallerCore(nums,idx,tmp,res,mid + 1,r);
        merge(nums,idx,tmp,res,l,mid,mid + 1,r);
    }

    void merge(vector<int> &nums,vector<int> &idx,vector<int> &tmp,vector<int> &res,int l1,int r1,int l2,int r2){
        int p1 = l1,p2 = l2,p = l1;
        while(p1 <= r1 && p2 <= r2){
            if(nums[idx[p1]] > nums[idx[p2]]){
                res[idx[p1]] += r2 - p2 + 1;
                tmp[p++] = idx[p1++];
            }
            else
                tmp[p++] = idx[p2++];
        }
        while(p1 <= r1) tmp[p++] = idx[p1++];
        while(p2 <= r2) tmp[p++] = idx[p2++];

        p = l1;
        while(p <= r2){
            idx[p] = tmp[p];
            p++;
        }
    }

};