## 题目

运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。

获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。

进阶:

你是否可以在 O(1) 时间复杂度内完成这两种操作？

示例:

```
LRUCache cache = new LRUCache( 2 /* 缓存容量 */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回  1
cache.put(3, 3);    // 该操作会使得密钥 2 作废
cache.get(2);       // 返回 -1 (未找到)
cache.put(4, 4);    // 该操作会使得密钥 1 作废
cache.get(1);       // 返回 -1 (未找到)
cache.get(3);       // 返回  3
cache.get(4);       // 返回  4
```

## 解答

[参考](https://www.youtube.com/watch?v=q1Njd3NWvlY)

* 需要实现O(1)的查找，那么需要用到hash表
* 因为LRU，所以get的节点要移动到队列首部，put需要将节点添加到队列首部，需要在O(1)内完成，那么应该使用链表

最后，如何在get时如何获取到链表中的节点？我们将hash表的value设置成连接节点的迭代器，因此通过key就能找到相应节点的迭代器。因为get时，可能删除链表中间的某个节点，要在O(1)内完成，那么使用双链表（STL的list）

那么链表节点是只保存value还是保存(key,value)？答案是后者，因为当缓存满时，需要删除链表结尾的节点，同时需要删除hash表中对应的项，因此需要获取节点的key

总的来说，就是hash表和list的两层结构：

<div align="center"> <img src="../img/146.png"/> </div>

代码如下：

```c++
class LRUCache {
public:
    LRUCache(int capacity) : hashtable() , ls() , cap(capacity) , curr(0) {}
    
    int get(int key) {
        if(hashtable.find(key) == hashtable.end())  return -1;
        auto itr = hashtable[key];
        if(itr == ls.begin())
            return itr->second;
        else{
            ls.push_front(pair<int,int>(itr->first,itr->second));
            auto new_itr = ls.begin();
            hashtable[key] = new_itr;
            ls.erase(itr);
            return ls.front().second;
        }
        return 1;
    }
    
    void put(int key, int value) {
        if(hashtable.find(key) != hashtable.end()){
            ls.erase(hashtable[key]);
            ls.push_front(pair<int,int>(key,value));
            auto new_itr = ls.begin();
            hashtable[key] = new_itr;
            return;
        }
        if(curr == cap){
            hashtable.erase(ls.back().first);
            ls.pop_back();
            curr--;
        }    
        ls.push_front(pair<int,int>(key,value));
        auto new_itr = ls.begin();
        hashtable[key] = new_itr;
        curr++;
    }
private:
    unordered_map<int,list<pair<int,int>>::iterator> hashtable;
    list<pair<int,int>> ls;
    int cap;
    int curr;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
```