对于每个数字，可以选择要或者不要，使用一个数组set来保存选择要的数字

在做下一次选择时，可能有两种情况：

1. set中的数字和已经等于target，此时将set存入结果中
2. 如果1不成立，并且到达结尾，此时不存储set，直接返回

由于允许重复使用一个数字，如果选择使用这个数字，因为可能会重复选择，所以继续在当前位置处理。如果不选择使用这个数字，则继续处理下一个数字

可以先对数组进行排序，如果加上当前数字的总和已经超过target，则停止这个路径的处理。通过剪枝，去掉不可能的子集

