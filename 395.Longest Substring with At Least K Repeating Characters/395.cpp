class Solution {
public:
    int longestSubstring(string s, int k) {
        vector<int> cases(26,0);
        for(char c : s) cases[c - 'a']++;
        
        int len = s.length();
        int idx = 0;
        while(idx < len && cases[s[idx] - 'a'] >= k) {idx++;}
        if(idx == len)  return len;
        
        int left = longestSubstring(s.substr(0,idx),k);
        //这里是个优化：跳过所有相连的、出现次数少于k次的字符
        while(idx < len && cases[s[idx] - 'a'] < k) {idx++;}
        int right = longestSubstring(s.substr(idx),k);
        
        return max(left,right);
    }
};