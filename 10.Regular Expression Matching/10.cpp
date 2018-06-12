class Solution {
public:
    bool isMatch(string s, string p) {
        int len1 = s.length(),len2 = p.length();
        
        bool **state = new bool*[len1 + 1];
        for(int i = 0;i <= len1;i++)
            state[i] = new bool[len2 + 1];
        
        //第一列，p = ""
        state[0][0] = true;
        for(int i = 1;i <= len1;i++)    state[i][0] = false;
        
        //第一行，s = ""
        state[0][1] = false;
        for(int j = 2;j <= len2;j++)    state[0][j] = (p[j - 1] == '*') ? (state[0][j - 2]) : false;
        
        for(int i = 1;i <= len1;i++)
            for(int j = 1;j <= len2;j++){
                if(p[j - 1] == '*')
                    state[i][j] = state[i][j - 2] || ((p[j - 2] == '.' || p[j - 2] == s[i - 1]) && state[i - 1][j]);
                else if(p[j - 1] == '.')
                    state[i][j] = state[i - 1][j - 1];
                else
                    state[i][j] = (p[j - 1] == s[i - 1]) && state[i - 1][j - 1];
            }
        
        return state[len1][len2];
    }
};