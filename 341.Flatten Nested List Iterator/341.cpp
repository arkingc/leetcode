/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        //将最外层的list收尾迭代器压入栈
        begin.push(nestedList.begin());
        end.push(nestedList.end());
    }

    int next() {
        if(hasNext()) return (begin.top()++)->getInteger();
        return 0;
    }

    bool hasNext() {
        while(begin.size()){//说明至少还有一层list未处理完
            //该层list遍历完毕，弹出两个迭代器继续处理外层list
            if(begin.top() == end.top()){
                begin.pop();
                end.pop();
            }
            else{//该层list还有剩余，继续处理该层
                auto itr = begin.top();
                if(itr->isInteger())  return true;
                //遇到一个嵌套list，前移迭代器，准备压入嵌套list的迭代器，处理嵌套层
                begin.top()++;
                begin.push(itr->getList().begin());
                end.push(itr->getList().end());
            }
        }
        return false;
    }
private:
    stack<vector<NestedInteger>::iterator> begin,end;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */