class Solution {
public:
    bool isPalindrome(string s) {
        for(int l = 0,r = s.length() - 1;l < r;l++,r--) {
            while(!isalnum(s[l]) && l < r) {l++;}
            while(!isalnum(s[r]) && r > l) {r--;}
            if(toupper(s[l]) != toupper(s[r]))  return false;
        }
        return true;
    }
};