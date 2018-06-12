class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> map;
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;
        int res = map[s[0]],prev = map[s[0]];
        for(int i = 1;i < s.length();i++){
            if(map[s[i]] > prev)
                res += map[s[i]] - prev * 2;
            else
                res += map[s[i]];
            prev = map[s[i]];
        }
        return res;
    }
};