class MyCalendar {
public:
    
    map<int, int> mp;
    
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto i = mp.lower_bound(start);
        if(i!=mp.end() && i->first < end)
        {
            return false;
        }
        if(i!=mp.begin() && (--i)->second > start)
        {
            return false;
        }
        mp[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
