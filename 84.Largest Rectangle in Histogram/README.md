## 题目

给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积

<div align="center"> <img src="../img/84.png"/> </div>

示例:

```
输入: [2,1,5,6,2,3]
输出: 10
```

## 解答

使用一个栈保存高度：

1. 升序时，压入栈中
2. 发生降序时，从栈顶弹出元素，计算，并且根据计算结果更新最大矩阵的值。重复这个过程直到栈中的高度重新保持升序

以题目中的示例，当遇到1，2，0(这个是添加到heights末尾的元素，为的是保证最后一次计算)时会进行计算，每次会计算的面积以图中的虚线表示：

<div align="center"> <img src="../img/84-1.png"/> </div>

```c++
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
```