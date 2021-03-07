class MyHashMap {
public:
    /** Initialize your data structure here. */
    
    vector<vector<pair<int, int>>> v;
    int size;
    MyHashMap() {
        size = 1000000;
        v.resize(size);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int idx = key%size;
        vector<pair<int, int>> &temp = v[idx];
        for(auto i = temp.begin(); i!=temp.end(); i++ )
        {
            if(i->first == key)
                i->second=value;
                return ;
        }
        temp.push_back({key, value});
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int idx = key%size;
        vector<pair<int, int>> &row = v[idx];
        
        for(auto i = row.begin() ; i!=row.end() ; i++)
        {
            if(i->first==key)
            {
                return i->second;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int idx = key%size;
        vector<pair<int, int>> &row = v[idx];
        
        for(auto i = row.begin();i!=row.end();i++)
        {
            if(i->first == key)
            {
                row.erase(i);
                return;
            }
        }
    }
};
