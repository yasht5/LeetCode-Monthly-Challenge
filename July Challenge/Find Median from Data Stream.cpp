class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<long> small, large;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num) ;
        large.push(-small.top());
        small.pop();
        if(small.size() < large.size())
        {
            small.push(-large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        return small.size() > large.size() ? small.top() : (small.top() - large.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
