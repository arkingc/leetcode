## 题目

给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 ```(i, j, k, l)``` ，使得 ```A[i] + B[j] + C[k] + D[l] = 0```

为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -2^28 到 2^28 - 1 之间，最终结果不会超过 2^31 - 1 。

例如:

```
输入:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

输出:
2

解释:
两个元组如下:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
```

## 解答

每个数组中选取一个数，总共4个数构成一个排列，判断这4个数相加的结果是否等于0，因为每个数组的元素个数为n，那么总共有n^4种路径

### 1）暴力法

通过上面的分析，可以使用4个循环，针对每条路径（每种排列），判断是否符合要求，符合则计数加1

```c++
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int count = 0;
        for(int num1 : A)
            for(int num2 : B)
                for(int num3 : C)
                    for(int num4 : D)
                        if(num1 + num2 + num3 + num4 == 0)
                            count ++;
        return count;  
    }
};
```

* **时间复杂度**：O(n^4)
* **空间复杂度**：O(1)

这种方法显然会超时：**28/48 test cases passed**

### 2）空间换时间1

如果使用一个集合保存最后一个数组的数，那么只需求出前3个数的所有排列，然后判断集合中有多少个数等于-num1-num2-num3，那么计数就加多少。这样通过O(n)的空间换取O(n)的时间：

```c++
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int count = 0;
        
        unordered_multiset<int> set;
        for(int num4 : D)   set.insert(num4);
        
        for(int num1 : A)
            for(int num2 : B)
                for(int num3 : C)
                        count += set.count(-num1-num2-num3);
        return count;  
    }
};
```

* **时间复杂度**（忽略set.count）：O(n^3)
* **空间复杂度**：O(n)

这种方法还是会超时：**40/48 test cases passed**

### 3）空间换时间2

进一步，可以使用set保存前2个数组所有元素相加的和，那么只需2层循环遍历后2个数组，然后计算在集合中有多少个元素等于-num3-num4就可以再用O(n)的空间复杂度换O(n)的时间复杂度：

```c++
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int count = 0;
        
        unordered_multiset<int> set;
        
        for(int num1 : A)
            for(int num2 : B)
                set.insert(num1+num2);
        
        for(int num3 : C)
            for(int num4 : D)
                count += set.count(-num3-num4);
        
        return count;  
    }
};
```

* **时间复杂度**（忽略set.count）：O(n^2)
* **空间复杂度**：O(n^2)

这种方法依然会超时：**47/48 test cases passed**

### 4）空间换时间3

观察发现，上面使用的是set，在计数时调用了count函数，这个函数还是会遍历相同的元素，因此存在一定开销。可以将set换成map，key为num1+num2的值，value为相同key的排列数。所以避免了调用count

```c++
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
```

* **时间复杂度**：O(n^2)
* **空间复杂度**：O(n^2)