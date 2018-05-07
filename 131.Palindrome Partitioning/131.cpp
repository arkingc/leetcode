class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        
        dfs(s,path,res);
        
        return res;
    }
    
    void dfs(string s,vector<string> &path,vector<vector<string>> &res){
        if(s.empty())   res.push_back(path);
        
        for(int len = 1;len <= s.size();len++){
            string substr = s.substr(0,len);
            if(isPalindrome(substr)){
                path.push_back(substr);
                dfs(s.substr(len),path,res);
                path.pop_back();
            }
        }
    }
    
private:
    bool isPalindrome(const string &str){
        int l = 0,r = str.size() - 1;
        while(l < r){
            if(str[l++] == str[r--])    continue;
            else return false;
        }
        return true;
    }
};