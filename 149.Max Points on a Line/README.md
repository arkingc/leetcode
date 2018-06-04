## 题目

给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。

示例 1:

```
输入: [[1,1],[2,2],[3,3]]
输出: 3
解释:
^
|
|        o
|     o
|  o  
+------------->
0  1  2  3  4
```

示例 2:

```
输入: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
输出: 4
解释:
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6
```

## 解答

遍历每一个点p，计算点p与其余点组成的直线中，哪一条上面的点最多。使用一个map存储每一条直线，key是一个pair，表示这条直线的斜率，value是这条直线上点的个数

因此，为计算一个点在哪条直线上，只需要计算这个点和p的斜率，然后将map中对应直线的点数加1。注意可能存在与p重合的点，因此使用一个变量samePoints计算与p重合的点的个数，那么p和其余点的所有直线中，点数最大就是map中的最大value加上samePoints

由于遍历到后面时，前面的点与后面的点组成的直线已经计算过，所以每个点只需要和其后剩余的点进行分析即可

```c++
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int num = points.size();
        int res = 0;
        for(int i = 0;i < num;i++){
            map<pair<int,int>,int> lines;
            int samePoints = 1,localmax = 0;
            for(int j = i + 1;j < num;j++){
                if(points[i].x == points[j].x && points[i].y == points[j].y)
                    samePoints++;
                else
                    localmax = max(localmax,++lines[getSlope(points[i],points[j])]);
            }
            res = max(res,localmax + samePoints);
        }
        return res;
    }
private:
    pair<int,int> getSlope(const Point &p1,const Point &p2){
        int dx = p1.x - p2.x;
        int dy = p1.y - p2.y;
        
        if(dx == 0) return pair<int,int>(0,p1.y);
        if(dy == 0) return pair<int,int>(p1.x,0);
        
        int d = gcd(dx,dy);
        
        return pair<int,int>(dx/d,dy/d);
    }
    
    //求最大公约数
    int gcd(int x,int y){
        return y == 0 ? x : gcd(y,x % y);
    }
};
```