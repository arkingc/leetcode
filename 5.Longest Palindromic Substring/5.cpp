class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() <= 1) return s;
        
        int len = s.length();
        string res = "";
        //做了状态压缩
        bool *state = new bool[len];
        state[len - 1] = true;
        for(int i = len - 2;i >= 0;i--){
            for(int j = len - 1;j >= i;j--){
                if(i == j)
                    state[j] = true;
                else if(s[i] == s[j]){
                    if(i == j - 1)   state[j] = true;
                    else    state[j] = state[j - 1];
                }
                else 
                    state[j] = false;
                if(state[j] && (j - i + 1) > res.length())
                    res = s.substr(i,(j - i + 1));
            }
        }
        return res;
    }
};