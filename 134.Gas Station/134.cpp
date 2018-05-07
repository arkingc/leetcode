class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;      //起始位置
        int remain = 0;     //当前剩余燃料
        int debt = 0;       //前面没能走完的路上欠的债
        
        for(int i = 0;i < gas.size();i++){
            remain += gas[i] - cost[i];
            if(remain < 0){
                start = i + 1;
                debt += remain;
                remain = 0;
            }
        }
        
        return debt + remain >= 0 ? start : -1;
    }
};