class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        bool *state = new bool[s.size() + 1];
        for(int i = 0;i < s.size();i++) state[i] = false;
        state[s.size()] = true;
        
        for(int idx = s.size() - 1;idx >= 0;idx--){
            for(int len = 1;len <= s.size() - idx && !state[idx];len++)
                if(dict.find(s.substr(idx,len)) != dict.end())
                    state[idx] = state[idx + len];
        }
        
        return state[0];
    }
};