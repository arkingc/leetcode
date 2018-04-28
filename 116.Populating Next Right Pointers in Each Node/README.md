题目要求使用常量空间，不然可以使用一个队列按层迭代遍历树，每遍历一层，将节点链接起来

那么不用队列如何实现？题目假设所有叶子节点都在同一层，并且每个非叶子节点都有两个孩子，那么假设有如下树结构：

```
            node
           /    \
        node    node
       /    \   /   \
     node node node node
    /  \  /  \ /  \  /  \
   n   n n   n n  n  n   n
```

假设对于树种的任意node，如果node不是叶子节点，那么可以将node的左子节点和右子节点连起来：

```c++
node->left->next = node->right;
```

如果这样处理，那么按前序遍历整棵树，处理之后：

```
            node
           /    \
        node----node
       /    \   /   \
     node-node node-node
    /  \  /  \ /  \  /  \
   n---n n---n n--n  n---n
```

这样的话，每一层的节点虽然能两两串起来，但是每对节点之间还是存在空隙，如第3层的中间两个节点没连接起来，最下层的第2个节点和第3个节点、第4个节点与第5个节点。。。

那么怎么处理这些节点的链接？比方说第三层的第2个节点怎么连到第三层的第3个节点，肯定是不能等到遍历到第3层的第2个节点才处理，因为这样的话它无法获取到第3层的第3个节点。所以在遍历到其父节点时就进行处理：

```
//node为第二层的第1个节点
node->right->next = node->next-left;
```

**所以在前序遍历过程中，每遍历到一个节点时，要处理2个链接**：

```c++
node->left->next = node->right;
node->right->next = node->next-left;
```

同样以前面的例子为例，整个处理过程如下：

```
//初始状态
            node
           /    \
        node    node
       /    \   /   \
     node node node node
    /  \  /  \ /  \  /  \
   n   n n   n n  n  n   n

//处理根节点
            node
           /    \
        node----node
       /    \   /   \
     node node node node
    /  \  /  \ /  \  /  \
   n   n n   n n  n  n   n

//处理根节点的左子节点
            node
           /    \
        node----node
       /    \   /   \
     node-node-node node
    /  \  /  \ /  \  /  \
   n   n n   n n  n  n   n

//...
            node
           /    \
        node----node
       /    \   /   \
     node-node-node node
    /  \  /  \ /  \  /  \
   n---n-n   n n  n  n   n

//...
            node
           /    \
        node----node
       /    \   /   \
     node-node-node node
    /  \  /  \ /  \  /  \
   n---n-n---n-n  n  n   n

//处理根节点的右子节点
            node
           /    \
        node----node
       /    \   /   \
     node-node-node-node
    /  \  /  \ /  \  /  \
   n---n-n---n-n  n  n   n

//...
            node
           /    \
        node----node
       /    \   /   \
     node-node-node-node
    /  \  /  \ /  \  /  \
   n---n-n---n-n--n--n   n

//...
            node
           /    \
        node----node
       /    \   /   \
     node-node-node-node
    /  \  /  \ /  \  /  \
   n---n-n---n-n--n--n---n
```