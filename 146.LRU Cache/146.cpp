class LRUCache {
public:
    LRUCache(int capacity) : hashtable() , ls() , cap(capacity) , curr(0) {}
    
    int get(int key) {
        if(hashtable.find(key) == hashtable.end())  return -1;
        auto itr = hashtable[key];
        if(itr == ls.begin())
            return itr->second;
        else{
            ls.push_front(pair<int,int>(itr->first,itr->second));
            auto new_itr = ls.begin();
            hashtable[key] = new_itr;
            ls.erase(itr);
            return ls.front().second;
        }
        return 1;
    }
    
    void put(int key, int value) {
        if(hashtable.find(key) != hashtable.end()){
            ls.erase(hashtable[key]);
            ls.push_front(pair<int,int>(key,value));
            auto new_itr = ls.begin();
            hashtable[key] = new_itr;
            return;
        }
        if(curr == cap){
            hashtable.erase(ls.back().first);
            ls.pop_back();
            curr--;
        }    
        ls.push_front(pair<int,int>(key,value));
        auto new_itr = ls.begin();
        hashtable[key] = new_itr;
        curr++;
    }
private:
    unordered_map<int,list<pair<int,int>>::iterator> hashtable;
    list<pair<int,int>> ls;
    int cap;
    int curr;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */