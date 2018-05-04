const int range = 256;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int state[range];
        int globalmax = 0,localmax = 0;
        int beginidx = 0;
        
        for(int i = 0;i < range;i++)    state[i] = -1;
        
        for(int idx = 0;idx < s.size();idx++){
            if(state[s[idx]] < 0 || state[s[idx]] < beginidx){
                localmax++;
                state[s[idx]] = idx;
                
                if(localmax > globalmax)    globalmax = localmax;
            }
            else{
                beginidx = state[s[idx]] + 1;
                localmax = idx - beginidx + 1;
                state[s[idx]] = idx;
            }
        }
        
        return globalmax;
    }
};