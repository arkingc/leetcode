class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> idxArray(26,-1);
        for(int i = 0;i < s.length();i++){
            if(idxArray[s[i] - 'a'] == -1)   idxArray[s[i] - 'a'] = i;
            else idxArray[s[i] - 'a'] = -2;
        }
        
        int minIdx = -1;      
        for(int idx : idxArray)
            if(idx != -1 && idx != -2){
                if(minIdx == -1)    minIdx = idx;
                else if(idx < minIdx) minIdx = idx;
            }
        
        return minIdx;
    }
};