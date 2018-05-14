class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(denominator == 0)    return "";
        if(numerator == 0)  return "0";
        
        bool negative = (numerator < 0) ^ (denominator < 0);
        long long lnumerator = abs((long long)numerator);
        long long ldenominator = abs((long long)denominator);
        unordered_map<int,int> map;//<numerator,index>
        string res = (negative ? "-" : "") + to_string(lnumerator / ldenominator) + (lnumerator % ldenominator ? "." : "");
        lnumerator = lnumerator % ldenominator; 
        
        while(lnumerator && map.find(lnumerator) == map.end()){
            map[lnumerator]=res.size();
            lnumerator *= 10;
            res = res + to_string(lnumerator / ldenominator);
            lnumerator = lnumerator % ldenominator;
        }
        
        if(lnumerator){
            int idx = map.find(lnumerator)->second;
            res = res.substr(0,idx) + "(" + res.substr(idx) + ")";
        }
        
        return res;
    }
};