## 题目

统计所有小于非负整数 n 的质数的数量。

示例:

```
输入: 10
输出: 4
解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
```

## 解答

创建一个bool数组state，[0,n)中非负数标位false，最后统计数组中为true的数量，即质数的数量

一个质数只能被1和该数本身整除，那么：

```
2*2,2*3,2*4,...  //4,6,8,...
3*3,3*4,3*5,...  //9,12,15,...
4*4,4*5,4*6,...  //16,20,24,...
...
```

都不是质数，因此，只需要设变量i为2\~m（i\*i<n），然后j为i\~n(i\*j<n)，设置bool数组中下标为i\*j的元素为false即可

可以将i和j看成：j个i，j不必从1开始，因为如果j从1开始，可以互换i和j的概念，理解成i个j。比如说i=4，j=2时，可以理解成4个2，那么当i=2，j=4时，已经求过了，所以j从i开始

除此之外，如果state[i]为false，可以直接跳到i+1处理，因为如果state[i]为true，那么之前肯定存在一个数m\*n=i，然后将i设置为了false。那么i\*i,i\*(i+1),i\*(i+2),...的序列也肯定和之前的一个序列重合，比如当i=2时，设置了i=4为false，那么当i=4就不用处理了，因为4,8,12,...与i=2时的序列的一部分重合

```c++
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2)  return 0;
        
        bool *state = new bool[n];
        for(int i = 0;i < n;i++)    state[i] = true;
        state[0] = false;
        state[1] = false;
        for(int i = 2;i * i < n;i++)
            if(state[i])
                for(int j = i;i * j < n;j++)
                    state[i * j] = false;
 
        
        int count = 0;
        for(int i = 2;i < n;i++)
            if(state[i])
                count++;
        return count;
    }
};
```