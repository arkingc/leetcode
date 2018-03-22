class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n <= 0)
            return vector<string>();
        
        vector<string> res;
        string s;
        generateParenthesis(s,n,n,res);
        return res;
    }
    
private:
    void generateParenthesis(string s,int left,int right, vector<string> &res){
        if(!left && !right){
            res.push_back(s);
            return;
        }
        
        if(left == right) generateParenthesis(s+'(',left-1,right,res);
        else if(left == 0)  generateParenthesis(s+')',left,right-1,res);
        else {
            generateParenthesis(s+')',left,right-1,res);
            generateParenthesis(s+'(',left-1,right,res);
        }
    }
};