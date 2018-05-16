class Solution {
public:
    int calculate(string s) {
        deque<int> nums;
        deque<char> ops;
        
        int i = 0;
        for(int j = i;j < s.size();j++){
            if(s[j] == '+' || s[j] == '-' || s[j] == '*' || s[j] == '/'){
                int num = stoi(s.substr(i,j - i));
                if(!ops.empty() && (ops.back() == '*' || ops.back() == '/')){
                    if(ops.back() == '*')
                        nums.back() = nums.back() * num;
                    else
                        nums.back() = nums.back() / num;
                    ops.pop_back();
                }
                else
                    nums.push_back(num);
                ops.push_back(s[j]);
                i = j + 1;
            }
        }
        
        nums.push_back(stoi(s.substr(i,s.size() - i)));//最后一个数
        if(!ops.empty() && (ops.back() == '*' || ops.back() == '/')){
            int num = nums.back();nums.pop_back();
            if(ops.back() == '*')
                nums.back() = nums.back() * num;
            else
                nums.back() = nums.back() / num;
            ops.pop_back();
        }
        
        while(nums.size() > 1){
            int num = nums.front(); nums.pop_front();
            if(ops.front() == '+')
                nums.front() = num + nums.front();
            else if(ops.front() == '-')
                nums.front() = num - nums.front();
            ops.pop_front();
        }
        
        return nums.front();
    }
};