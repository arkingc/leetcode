## 题目

给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。画 n 条垂直线，使得垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

注意：你不能倾斜容器，n 至少是2。

## 解答

使用两个指针l和r，分别指向最左边的垂直线和最右边的垂直线，因此`r-1`就是容器的宽，`min(height[l],height[r])`就是容器的高，可以求出盛水量，为了盛更多的水，需要更大的面积，l和r向中间移动时，宽会变小，那么要得到更大的面积，高必须增加，因此选择l和r中高度较小者向中间移动，直到碰到一个更高的垂直线，此时判断是否更新最大盛水量。这个过程一直持续到`l>=r`

```c++
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0,r = height.size() - 1;
        int res = 0;
        while(l < r){
            int minHeight = min(height[l],height[r]);
            res = max(res , (r - l) * minHeight);
            while(l < r && height[l] <= minHeight)  l++;
            while(l < r && height[r] <= minHeight)  r--;
        }
        return res;
    }
};
```