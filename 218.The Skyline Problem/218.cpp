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