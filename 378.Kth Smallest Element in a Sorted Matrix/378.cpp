class Solution {
public:
    struct compare{
        bool operator()(const pair<int,pair<int,int>> &p1,const pair<int,pair<int,int>> &p2){
            return p1.first > p2.first;
        }
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //template <class T, class Sequence = vector<T>, class Compare = less<typename Sequence::value_type> >
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,compare> pq;
        
        for(int i = 0;i < matrix.size();i++)    
            pq.push(make_pair(matrix[i][0],make_pair(i,0)));
        
        int res,cols = matrix[0].size();
        while(k--){
            res = pq.top().first;
            int i = pq.top().second.first,j = pq.top().second.second;
            pq.pop();
            if(j < cols - 1)
                pq.push(make_pair(matrix[i][j + 1],make_pair(i,j+1)));
        }  
        
        return res;
    }
};