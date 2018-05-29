class Solution {
public:
    bool isMatch(string s, string p) {
        int len1 = s.length(),len2 = p.length();
        
        vector<vector<char>> matches(len1 + 1,vector<char>(len2 + 1));
        for(int i = 0;i < len1;i++)  // p == ""
            matches[i][len2] = 0;
        matches[len1][len2] = 1;       // p == "" && s == ""
        for(int j = len2 - 1;j >= 0;j--) // s == ""
            matches[len1][j] = (p[j] == '*' && matches[len1][j + 1]);
        
        for(int i = len1 - 1;i >= 0;i--){ // s.substr[i] match p.substr[j] ?
            for(int j = len2 - 1;j >= 0;j--){
                if(p[j] == '?')
                    matches[i][j] = matches[i + 1][j + 1];
                else if(p[j] == '*')
                    matches[i][j] = matches[i + 1][j] || matches[i][j + 1];
                else
                    matches[i][j] = (s[i] == p[j] && matches[i + 1][j + 1]);
            }
        }
        
        return matches[0][0];
    }
};