## 问题

给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

1. 左括号必须用相同类型的右括号闭合。
2. 左括号必须以正确的顺序闭合。

注意空字符串可被认为是有效字符串。

示例 1:

```
输入: "()"
输出: true
```

示例 2:

```
输入: "()[]{}"
输出: true
```

示例 3:

```
输入: "(]"
输出: false
```

示例 4:

```
输入: "([)]"
输出: false
```

示例 5:

```
输入: "{[]}"
输出: true
```

## 解答

使用一个栈，当出现‘(’,'{','['时，将字符压入栈中。当出现‘)’,'}',']'时，判断栈是否为空，不为空的话判断栈顶的元素是否是对应匹配的左括号，如果是则找到一对匹配的括号，弹出。当遍历完字符串后，如果栈不为空，说明存在左括号缺少对应匹配的右括号，那么返回false，否则返回true

```
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(int i = 0;i < s.length();i++){
            switch(s[i]){
                case ')':
                    if(stack.empty() || stack.top() != '(')
                        return false;
                    stack.pop();
                    break;
                case '}':
                    if(stack.empty() || stack.top() != '{')
                        return false;
                    stack.pop();
                    break;
                case ']':
                    if(stack.empty() || stack.top() != '[')
                        return false;
                    stack.pop();
                    break;
                default:
                    stack.push(s[i]);
                    break;
            }
        }
        return stack.empty() ? true : false;
    }
};
```