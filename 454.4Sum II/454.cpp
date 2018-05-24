class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int count = 0;
        
        unordered_map<int,int> map;
        
        for(int num1 : A)
            for(int num2 : B)
                map[num1+num2]++;
        
        for(int num3 : C)
            for(int num4 : D){
                auto itr = map.find(-num3-num4);
                if(itr != map.end())
                    count += itr->second;
            }
        
        return count;  
    }
};