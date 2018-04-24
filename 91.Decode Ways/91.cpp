class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0)   return 0;
        else if(s.size() == 1)  return s[0] == '0' ? 0 : 1;
        
        int end = s.size() - 1;
        int state1 = s[end] == '0' ? 0 : 1 , state2 = 1;
        int res;
        for(int i = end - 1;i >= 0; i--){
            if(s[i] == '0') res = 0;
            else if(stoi(s.substr(i,2)) > 26)    res = state1;
            else    res = state1 + state2;
            state2 = state1;
            state1 = res;
        }
        return res;
    }
};