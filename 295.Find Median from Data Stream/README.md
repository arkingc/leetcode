## 题目

中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

* void addNum(int num) - 从数据流中添加一个整数到数据结构中。
* double findMedian() - 返回目前所有元素的中位数。

示例：

```
addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
```

## 解答

使用一个最大堆和最小堆，最大堆保存较小一半的元素，最小堆保存较大一半的元素，第奇数个元素插入到最大堆，第偶数个元素插入到最小堆。如果本该插入一个堆中的新元素的值属于另一半（即，应该插入另一个堆），那么将其插入另一个堆并弹出堆顶元素，插入当前堆。根据元素个数决定是返回最大堆的堆顶元素还是两个堆堆顶元素的平均值

```c++
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder()  : total(0) , small() , large() {
    }
    
    void addNum(int num) {
        if(total % 2 == 0){//total为偶数时，压入的是第奇数个元素
            if(!small.empty() && small.top() < num){
                small.push(num);
                num = small.top();
                small.pop();
            }
            large.push(num);
        }
        else{              //total为奇数时，压入的是第偶数个元素
            if(!large.empty() && large.top() > num){
                large.push(num);
                num = large.top();
                large.pop();
            }
            small.push(num);
        }
        total++;
    }
    
    double findMedian() {
        if(total == 0)  return 0;
        if(total % 2 == 1){
            return large.top();
        }
        else
            return static_cast<double>(large.top() + small.top()) / 2;
    }
private:
    int total = 0;
    priority_queue<int,vector<int>,greater<int>> small; //存放较大的一半元素
    priority_queue<int,vector<int>,less<int>> large;    //存放较小的一半元素
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
```