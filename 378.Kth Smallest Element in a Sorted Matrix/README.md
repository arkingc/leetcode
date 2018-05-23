## 题目

给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第k小的元素。
请注意，它是排序后的第k小元素，而不是第k个元素

示例:

```
matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

返回 13。
```

说明: 

可以假设 k 的值永远是有效的, 1 ≤ k ≤ n^2 

## 解答

### 方法一

使用一个优先队列，这个队列中的元素个数等于矩阵的行数

将矩阵的第0列元素插入队列，此时队列头部的元素为matrix\[0\]\[0\]，是矩阵中最小的元素，对其执行出队操作，此时将matrix\[0\]\[1\]插入队列

由于优先队列使用堆实现，因此队列头部始终是最小的元素。每一个元素出队时，将其所在行的后一个元素插入队列。由于矩阵元素的性质，这样可以保证优先队列中始终包含当前所有剩余元素中最小的元素。那么只需做K次出队操作，第K个出队的元素就是答案

```c++
class Solution {
public:
    struct compare{
        bool operator()(const pair<int,pair<int,int>> &p1,const pair<int,pair<int,int>> &p2){
            return p1.first > p2.first;
        }
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //template <class T, class Sequence = vector<T>, class Compare = less<typename Sequence::value_type> >
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,compare> pq;
        
        for(int i = 0;i < matrix.size();i++)    
            pq.push(make_pair(matrix[i][0],make_pair(i,0)));
        
        int res,cols = matrix[0].size();
        while(k--){
            res = pq.top().first;
            int i = pq.top().second.first,j = pq.top().second.second;
            pq.pop();
            if(j < cols - 1)
                pq.push(make_pair(matrix[i][j + 1],make_pair(i,j+1)));
        }  
        
        return res;
    }
};
```

### 方法二

**基于值**的二分查找：首先找到矩阵所有元素中的最小值和最大值，求其中值，然后记录矩阵中小于该值的元素个数，根据这个计数结果与K进行比较来增大最小值或减小最大值

```c++
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(matrix.empty())  return -1;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        int small = matrix[0][0],large = matrix[rows - 1][cols - 1],median;
        while(small < large){
            median = (small + large) >> 1;
            int count = 0;
            for(int i = 0;i < rows;i++)
                count += std::upper_bound(matrix[i].cbegin(),matrix[i].cend(),median) - matrix[i].cbegin();
            if(count < k)
                small = median + 1;
            else
                large = median;
        }
        return small;
    }
};
```

使用题目开头给出的矩阵为例子:

```
matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,
```

上述代码会按下列步骤执行：

```
s            m           l 
1 , ...... , 8 , ...... ,16

count = 2 小于 k = 8, 因此 s = m + 1 = 9

s          m        l 
9 , ... , 12 , ... ,16

count = 6 小于 k = 8, 因此 s = m + 1 = 13

s    m         l 
13 , 14 , ... ,16

count = 8 等于 k = 8, 因此 l = m = 14

s|m  l
13 , 14

count = 8 等于 k = 8, 因此 l = m = 13

此时 s = l = 13循环终止，结果为13
```