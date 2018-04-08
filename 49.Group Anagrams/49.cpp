class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string,vector<string>> mp;
        
        for(int i = 0;i < strs.size();i++){
            string tp = strs[i];
            sort(tp.begin(),tp.end());
            
            if(mp.find(tp) == mp.end()){
                vector<string> v;
                v.push_back(strs[i]);
                mp.insert(pair<string,vector<string>>(tp,v));
            }
            else{
                mp.find(tp)->second.push_back(strs[i]);
            }
        }
        
        for(auto e : mp){
            res.push_back(e.second);
        }
        
        return res;
    }
};