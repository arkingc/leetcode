class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);   //保证最后一次处理
        stack<int> s;
        int max_area = 0;
        for(int i = 0;i < heights.size();i++){
            while(!s.empty() && heights[i] <= heights[s.top()]){
                int height = heights[s.top()];
                s.pop();
                int idx = s.empty() ? -1 : s.top();
                int width = i - idx - 1;
                if(width * height > max_area)   max_area = width * height;
            }
            s.push(i);
        }
        
        return max_area;
    }
};