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