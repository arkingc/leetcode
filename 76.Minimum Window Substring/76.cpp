class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> map;
        for(char c : t) map[c]++;
        
        int start = 0,i = 0,min = INT_MAX;
        int len = s.length(),total = t.length();
        for(int j = 0;j < s.length();j++){
            if(map.find(s[j]) != map.end())//如果遇到一个t中的字符
                if(map[s[j]]-- > 0)
                    total--;
            while(total == 0){//说明当前滑动窗口覆盖了t中的所有字符
                if(j - i + 1 < min){
                    min = j - i + 1;
                    start = i; //更新start的位置
                }
                //从滑动窗口左边回收字符，寻找下一个满足条件的滑动窗口
                //如果t中某些字符在滑动窗口中出现了多次，对于map中的计数会<0
                //如果++没有大于0，说明是遇到一个在滑动窗口中出现多次的字符
                //因此不增加total
                if(map.find(s[i]) != map.end()){
                    if(++map[s[i++]] > 0)
                        total++;
                }
                else    i++;
            }
        }
        
        return min == INT_MAX ? "" : s.substr(start,min);
    }
};