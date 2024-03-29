class UndergroundSystem {
public:
    map<int, pair<string, int>> checkin;
    map<string, pair<int, int>> checkout;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkin[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string, int> p = checkin[id];
        checkin.erase(id);
        
        string route = p.first + "," + stationName;
        
        checkout[route].first++;
        checkout[route].second+=t-p.second;        
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<int, int> p = checkout[startStation + "," + endStation];
        
        return (double)p.second/p.first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
