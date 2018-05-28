class Solution {
public:
    string countAndSay(int n) {
        if(n <= 0)  return "";
        else if(n == 1) return "1";
        
        string res = "1";
        while(--n){
            string s = "";
            char c = res[0];
            int count = 1;
            for(int i = 1;i < res.length();i++){
                if(res[i] == c) count++;
                else{
                    s += to_string(count) + c;
                    c = res[i];
                    count = 1;
                }
            }
            s += to_string(count) + c;
            res = s;
        }
        
        return res;
    }
};