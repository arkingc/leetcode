### 方法一（超时）

递归，如果已经到达下边界则只能往右走，如果已经到达右边界则只能向下走，否则既可以向左走也可以向右走

```c++
class Solution {
public:
    int uniquePaths(int m, int n) {
        int count = 0;
        
        uniquePaths(m,n,0,0,count);
        
        return count;
    }
    
private:
    void uniquePaths(int m,int n,int i,int j,int &count){
        if(i == m - 1 && j == n - 1){
            count++;
            return;
        }
        
        if(i == m - 1)  uniquePaths(m,n,i,j+1,count);
        else if(j == n - 1) uniquePaths(m,n,i+1,j,count);
        else{
            uniquePaths(m,n,i,j+1,count);
            uniquePaths(m,n,i+1,j,count);
        }
    }
};
```

### 方法二（Accepted）

假设已经求得位于(x,y)有m种走法到达右下角，那么在求(x,y-1)位置向右走和求(x-1,y)位置向下走时，就不必求重复问题

```c++
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m <= 0 || n <= 0)    return 0;
        if(m == 1 || n == 1)    return 1;
        
        vector<vector<int>> state;
        
        for(int i = 0;i < m;i++){
            vector<int> tp;
            for(int j = 0;j < n;j++){
                tp.push_back(0);
            }
            state.push_back(tp);
        }
        
        for(int i = 0;i < m;i++)    state[i][n-1] = 1;
        for(int j = 0;j < n;j++)    state[m-1][j] = 1;
        
        for(int i = m - 2;i >= 0;i--){
            for(int j = n - 2;j >= 0;j--){
                //状态转移方程
                state[i][j] = state[i+1][j] + state[i][j+1];
            }
        }
        
        return state[0][0];
    }
};
```

上述方法使用二维矩阵存储状态，还可以对状态进行压缩，使用一维矩阵存储状态：

```c++
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m <= 0 || n <= 0)    return 0;
        if(m == 1 || n == 1)    return 1;
        
        vector<int> state;
        
        for(int j = 0;j < n;j++)    state.push_back(1);
        
        for(int i = m - 2;i >= 0;i--){
            for(int j = n - 2;j >= 0;j--){
                //状态转移方程
                state[j] = state[j+1] + state[j];
            }
        }
        
        return state[0];
    }
};
```