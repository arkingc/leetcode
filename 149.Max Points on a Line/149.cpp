/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int num = points.size();
        int res = 0;
        for(int i = 0;i < num;i++){
            map<pair<int,int>,int> lines;
            int samePoints = 1,localmax = 0;
            for(int j = i + 1;j < num;j++){
                if(points[i].x == points[j].x && points[i].y == points[j].y)
                    samePoints++;
                else
                    localmax = max(localmax,++lines[getSlope(points[i],points[j])]);
            }
            res = max(res,localmax + samePoints);
        }
        return res;
    }
private:
    pair<int,int> getSlope(const Point &p1,const Point &p2){
        int dx = p1.x - p2.x;
        int dy = p1.y - p2.y;
        
        if(dx == 0) return pair<int,int>(0,p1.y);
        if(dy == 0) return pair<int,int>(p1.x,0);
        
        int d = gcd(dx,dy);
        
        return pair<int,int>(dx/d,dy/d);
    }
    
    //求最大公约数
    int gcd(int x,int y){
        return y == 0 ? x : gcd(y,x % y);
    }
};