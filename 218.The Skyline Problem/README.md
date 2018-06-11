## 题目

城市的天际线是从远处观看该城市中所有建筑物形成的轮廓的外部轮廓。现在，假设您获得了城市风光照片（图A）上显示的所有建筑物的位置和高度，请编写一个程序以输出由这些建筑物形成的天际线（图B）

<div align="center"> <img src="../img/218.png"/> </div>

每个建筑物的几何信息用三元组 [Li，Ri，Hi] 表示，其中 Li 和 Ri 分别是第 i 座建筑物左右边缘的 x 坐标，Hi 是其高度。可以保证 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX 和 Ri - Li > 0。您可以假设所有建筑物都是在绝对平坦且高度为 0 的表面上的完美矩形。

例如，图A中所有建筑物的尺寸记录为：[ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] 。

输出是以 [ [x1,y1], [x2, y2], [x3, y3], ... ] 格式的“关键点”（图B中的红点）的列表，它们唯一地定义了天际线。关键点是水平线段的左端点。请注意，最右侧建筑物的最后一个关键点仅用于标记天际线的终点，并始终为零高度。此外，任何两个相邻建筑物之间的地面都应被视为天际线轮廓的一部分。

例如，图B中的天际线应该表示为：[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ]。

说明:

* 任何输入列表中的建筑物数量保证在 [0, 10000] 范围内。
* 输入列表已经按升序排列在左边的 x 位置 Li 。
* 输出列表必须按 x 位排序。
* 输出天际线中不得有连续的相同高度的水平线。例如 [...[2 3], [4 5], [7 5], [11 5], [12 7]...] 是不正确的答案；三条高度为 5 的线应该在最终输出中合并为一个：[...[2 3], [4 5], [12 7], ...]

## 解答

[参考](https://www.youtube.com/watch?v=8Kd-Tn_Rz7s&vl=zh)

**扫描线的方法**

将大楼的左上角点称为“入”点，右上角的点称为“出”点。从左往右扫描，每当遇到一个点：

* 如果是一个“入”点，并且该点时当前最高的点，那么就将该点加入结果中
* 如果是一个“出”点，那么就需要找将自己（该大楼）移除后，那个那楼是最高的，即第二高的大楼的高度，将扫描线与其交点加入结果中

<div align="center"> <img src="../img/218-1.png"/> </div>

可以通过将高度改为对应负值来标识一个“出”点

注意几种特殊情况：

* 当一个大楼的右边与另一个大楼的最左边挨着，即第一个大楼的“出”点x坐标与第二个大楼的“入”点x坐标相等。此时扫描线应该先处理后一个大楼的“入”点，否则会添加一个错误的点。因为“出”点的高度用负值标识，所有”入“点都是正值，所以排序的时候，x相同时高度更高的点排在前面即可满足这种要求：

<div align="center"> <img src="../img/218-2.png"/> </div>

* 当两个大楼的”入“点或”出“点的x坐标相同时，即两个大楼的左边挨着，或者右边挨着时
    - 如果左边挨着：那么要从最高的大楼开始处理，否则会添加3个点
    - 如果右边挨着；那么要从最低的大楼开始处理，否则也会添加3个点（上面将”出“点高度用对应的负值标识，这样的处理在排序时，也能满足这个要求）

<div align="center"> <img src="../img/218-3.png"/> </div>

<br>

```c++
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<int> hs; //包含所有已处理过的左上角和右上角点的高度
        
        vector<pair<int,int>> es;//保存所有待处理点
        for(const auto &p : buildings){
            es.emplace_back(p[0],p[2]);  //左上角（“入”点）
            es.emplace_back(p[1],-p[2]); //右上角，高度取负值用以标识是个“出”点
        }
        
        auto comp = [](const pair<int,int> &p1,const pair<int,int> p2){
            //如果两个点x相同，则更高的点排在前面
            if(p1.first == p2.first)    return p1.second > p2.second;
            //如果两个点x不同，则x更小的排在前面
            return  p1.first < p2.first;
        };
        
        //对所有点排序，因为要用线段扫描，所以按x轴排序，x相同的点，较低的排前面
        sort(es.begin(),es.end(),comp); 
        
        vector<pair<int,int>> res;
        
        //遍历每个建筑的两个顶点
        for(const auto &p : es){
            int x = p.first; //x左标
            bool entering = p.second > 0; //是不是个“入”点
            int h = abs(p.second);  //得到实际高度
            
            if(entering){// 如果是一个“入”点
                if(h > maxHeight(hs))
                    res.emplace_back(x,h);
                hs.insert(h);
            } else { // 如果是一个“出”点
                hs.erase(hs.equal_range(h).first);
                if(h > maxHeight(hs))
                    res.emplace_back(x,maxHeight(hs));
            }
        }
        
        return res;
    }
    
private:
    int maxHeight(const multiset<int> &hs) const {
        if(hs.empty())  return 0;
        return *hs.rbegin();
    }
};
```