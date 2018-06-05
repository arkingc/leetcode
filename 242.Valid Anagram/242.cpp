class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> map;
        for(char c : s)
            map[c]++;
        
        for(char c : t){
            if(map[c] == 0) return false;
            else    map[c]--;
        }
        
        for(auto p : map)
            if(p.second > 0)
                return false;
        
        return true;
    }
};