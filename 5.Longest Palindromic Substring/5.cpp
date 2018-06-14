class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() <= 1) return s;
        
        string res = "";
        int j;
        for(int i = 0;i < s.length();i = j){
            //向右找到第一个不相同的字符，i~(j-1)为相同字符
            for(j = i + 1;j < s.length() && s[j] == s[i];j++) {}
            int len = longestPalindrome(s,i,j - 1);
            if(len > res.length())
                res = s.substr(i - (len - (j - i)) / 2,len);
        }
        return res;
    }
private:
    int longestPalindrome(const string &s,int i,int j){
        int l = i - 1,r = j + 1,len = s.length();
        int count = j - i + 1;
        while(l >= 0 && r < len && s[l--] == s[r++])
                count += 2;
        return count;
    }
};