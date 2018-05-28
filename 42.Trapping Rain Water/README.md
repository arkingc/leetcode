## 题目

给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水

<div align="center"> <img src="../img/42.png"/> </div>

示例:

```
输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6
```

## 解答

### 方法一（暴力法）

**把问题缩小到一个柱子上，考虑柱子i上能接多少雨水**。这取决于i左右两边最高的柱子：

* 假设包括柱子i在内的所有i左边的柱子中，最大者为max_left
* 包括i在内的所有右边的柱子中，最大者为max_right
 
那么柱子i上能接的雨水量就是min(max_left,max_right)-height[i]。因此遍历每个柱子，然后遍历左边求出max_left，遍历右边求出max_right，然后将每个柱子能接的雨水量加入结果中

```c++
class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0,sz = height.size();
        for(int bar = 0;bar < sz;bar++){
            int max_left = 0,max_right = 0;
            for(int left_bar = bar;left_bar >= 0;left_bar--)
                if(height[left_bar] > max_left) max_left = height[left_bar];
            for(int right_bar = bar;right_bar < sz;right_bar++)
                if(height[right_bar] > max_right)   max_right = height[right_bar];
            water += min(max_left,max_right) - height[bar];
        }
        
        return water;
    }
};
```

* **时间复杂度**：O(n^2)
* **空间复杂度**：O(1)

### 方法二（优化方法一）

方法一在求max_left和max_right时，需要遍历柱子i的左边和右边，如果可以优化这个过程，在O(1)时间求出max_left和max_right，就能将O(n^2)的时间复杂度降到O(n)

考虑使用两个数组，max_lefts和max_rights，对于max_lefts来说，下标i表示[0,i]的柱子中最高柱子的高度。那么max_lefts[i+1] = max(max_lefts[i],height[i+1])。因此只需要遍历一遍所就能求出max_lefts。同样，对于max_rights来说，下标i表示[i,sz-1]的柱子中最高柱子的高度...

```c++
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 2)  return 0;
        
        int water = 0,sz = height.size();
        vector<int> max_lefts(sz,0),max_rights(sz,0);
        max_lefts[0] = height[0],max_rights[sz - 1] = height[sz - 1];
        
        for(int bar1 = 1,bar2 = sz - 2;bar1 < sz && bar2 >= 0;bar1++,bar2--){
            max_lefts[bar1] = max(max_lefts[bar1 - 1],height[bar1]);
            max_rights[bar2] = max(max_rights[bar2 + 1],height[bar2]);
        }
        
        for(int bar = 0;bar < sz;bar++){
            int max_left = max_lefts[bar],max_right = max_rights[bar];
            water += min(max_left,max_right) - height[bar];
        }
        
        return water;
    }
};
```

* **时间复杂度**：O(n)
* **空间复杂度**：O(n)

### 方法三（栈）

用栈保存每个柱子的下标，当一个柱子的高度<=栈顶的柱子的高度时，将这个柱子(的下标)压入栈中。因此，在遇到一个比栈顶柱子要高的柱子前，栈中柱子的高度从栈底到栈顶是一个降序序列，那么栈中每个柱子都是后一个柱子储水量的边界柱子。当遇到一个柱子高于栈顶柱子时，说明栈顶柱子出现了第一个左右边界柱子，那么计算其储水量，加入结果中。此时，相当于区间内最低的坑已经储上了水，因此可以将栈顶元素弹出，如此反复计算，直到栈顶元素大于等于新的柱子，然后将新的柱子(的下标)压入栈中，处理下一个柱子

```c++
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int water = 0,sz = height.size();
        for(int bar = 0;bar < sz;bar++){
            while(!s.empty() && height[bar] > height[s.top()]){
                int low_bar = s.top();
                s.pop();
                if(s.empty()) break;
                int left_bound = s.top();
                water += (bar - left_bound - 1) * (min(height[bar],height[left_bound]) - height[low_bar]); 
            }
            s.push(bar);
        }
        
        return water;
    }
};
```

* **时间复杂度**：O(n)
* **空间复杂度**：O(n)

### 方法四（两个指针）

使用两个变量max_left和max_right，分别表示左边柱子的最高者和右边柱子的最高者，初始化为最左边柱子的高度和最右边柱子的最高者

另外使用两个指针left_bar和right_bar，分别表示左边的一个柱子和右边的一个柱子，初始化为最左边的柱子和最右边的柱子。现在不考虑中间的柱子怎么样，只分析这两个指针所表示的柱子

假设left_bar和right_bar中高度较低者为left_bar：

* 如果left_bar比max_left要低，那么left_bar上面能储水max_left-left_bar
* 否则，left_bar比左边的柱子都要高，那么需要更新max_left的值

经过上面的处理后，递增left_bar，继续处理下一个柱子

同理，如果ç高度较低者为right_bar：

* 如果right_bar比max_right要低，那么right_bar上面能储水max_right-right_bar
* 否则，right_bar比右边的柱子都要高，那么需要更新max_right的值

经过上面的处理后，递减right_bar，继续处理下一个柱子

这里可能有个疑问：为什么增加储水量时不考虑另外一个边界？原因在于每次更新max_left或max_right时，都是left_bar和right_bar中高度较低者，因此，另外一边必然存在一个边界大于max_left或max_right

```c++
class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0,sz = height.size();
        int left_bar = 0,right_bar = sz - 1;
        int max_left = 0,max_right = 0;
        
        while(left_bar < right_bar){
            if(height[left_bar] < height[right_bar]){
                if(height[left_bar] < max_left) water += max_left - height[left_bar];
                else    max_left = height[left_bar];
                left_bar++;
            }
            else{
                if(height[right_bar] < max_right) water += max_right - height[right_bar];
                else    max_right = height[right_bar];
                right_bar--;
            }
        }
        
        return water;
    }
};
```

* **时间复杂度**：O(n)
* **空间复杂度**：O(1)

