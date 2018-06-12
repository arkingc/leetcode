class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)    return "";
        if(strs.size() == 1)    return strs[0];
        
        string res = "";
        int i = 0;
        while(i < strs[0].length()){
            char c = strs[0][i];
            int j = 1;
            for(;j < strs.size() && i < strs[j].length();j++)
                if(strs[j][i] != c)
                    break;
            if(j < strs.size()) return res;
            else{
                res += c;
                i++;
            }
        }
        return res;
    }
};