## 题目

打乱一个没有重复元素的数组

示例：

```c++
// 以数字集合 1, 2 和 3 初始化数组。
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// 打乱数组 [1,2,3] 并返回结果。任何 [1,2,3]的排列返回的概率应该相同。
solution.shuffle();

// 重设数组到它的初始状态[1,2,3]。
solution.reset();

// 随机返回数组[1,2,3]打乱后的结果。
solution.shuffle();
```

## 解答

使用[Fisher–Yates shuffle洗牌算法](https://www.youtube.com/watch?v=tLxBwSL3lPQ)

Fisher–Yates shuffle洗牌算法的思想是，每次从未处理的牌中随机选择一个，与未处理牌中最后一张牌交换，从而打乱顺序。算法本身没有保证在取每个随机数的时候是等概率的，它保证的是可以等概率的生成给定数组的任一排列。对于n张牌的数组，处理过程如下：

* 第一次：从[0,n-1]中，随机选择一个位置k1，交换位置k1和位置n-1的元素
* 第二次：从[0,n-2]中，随机选择一个位置k2，交换位置k2和位置n-2的元素
* ...