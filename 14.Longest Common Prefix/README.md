## 题目

编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

```
输入: ["flower","flow","flight"]
输出: "fl"
```

示例 2:

```
输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
```

说明:

所有输入只包含小写字母 a-z 。

## 解答

### 方法一：垂直扫描

首先判断所有字符串第一个字符是否相等，然后判断第二个，第三个...

```c++
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)    return "";
        if(strs.size() == 1)    return strs[0];
        
        string res = "";
        int i = 0;
        while(i < strs[0].length()){
            char c = strs[0][i];
            int j = 1;
            for(;j < strs.size() && i < strs[j].length();j++)
                if(strs[j][i] != c)
                    break;
            if(j < strs.size()) return res;
            else{
                res += c;
                i++;
            }
        }
        return res;
    }
};
```

### 方法二：分治

将字符串分为2组，求出第一组的前缀和第二组的前缀，然后求两个前缀字符串的公共前缀：

<div align="center"> <img src="../img/14-1.png"/> </div>

```c++
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)    return "";
        if(strs.size() == 1)    return strs[0];
        
        return longestCommonPrefix(strs,0,strs.size() - 1);
    }
private:
    string longestCommonPrefix(vector<string>& strs,int l,int r){
        if(l > r)   return "";
        if(l == r)  return strs[l];
        
        int mid = (l + r) >> 1;
        string s1 = longestCommonPrefix(strs,l,mid);
        string s2 = longestCommonPrefix(strs,mid + 1,r);
        return longestCommonPrefix(s1,s2);
    }
    
    string longestCommonPrefix(const string &s1,const string &s2){
        string res = "";
        int minLen = min(s1.length(),s2.length());
        for(int i = 0;i < minLen;i++){
            if(s1[i] != s2[i])  break;
            else   res += s1[i];
        }
        return res;
    }
};
```

### 方法三：二分查找

以第一个字符串为模板，首先判断其前半部分是否是其余n-1个字符串的前缀；

* 如果是，则添加后半部分字符串的前半部分，使得前缀更长，继续判断是否是其余n-1个字符串的前缀
* 如果不是，则判断前半部分字符串的前半部分是否是其余n-1个字符串的前缀...

<div align="center"> <img src="../img/14-2.png"/> </div>

```c++
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)    return "";
        if(strs.size() == 1)    return strs[0];
        
        int l = 0,r = strs[0].length() - 1;
        string res = "";
        while(l <= r){
            int mid = (l + r) / 2;
            string prefix = strs[0].substr(0,mid + 1);
            if(longestCommonPrefix(strs,prefix)){
                l = mid + 1;
                res = prefix;
            }
            else
                r = mid - 1;
        }
        return res;
    }
private:
    bool longestCommonPrefix(vector<string>& strs,const string &s){
        int len = s.length();
        int i = 1;
        for(;i < strs.size() && strs[i].length() >= len;i++)
            for(int j = 0;j < len;j++)
                if(strs[i][j] != s[j])
                    return false;
        if(i < strs.size()) return false;
        return true;
    }
};
```