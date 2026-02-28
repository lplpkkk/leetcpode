class LRUCache {
private:
    int cap; 
    list<pair<int,int>> cache; //key, val
    unordered_map<int, list<pair<int,int>> ::iterator> m;    

    void make_recent(int key){
        auto it=m[key];

        //(dst, list, src)
        cache.splice(cache.begin(),cache,it);
        return;
    }

public:
    LRUCache(int capacity):cap(capacity){}
    
    int get(int key) {
        if(m.find(key)==m.end()){
            return -1;
        }

        make_recent(key);
        auto it=m[key];

        return it->second;
    }
    
    void put(int key, int value) {
        //can we find?
        if(m.find(key)!=m.end()){
            m[key]->second=value;
            make_recent(key);
            return;
        }
        //out of capacity?
        if(cache.size()==cap){
            //evict last
            int last_key=cache.back().first;
            m.erase(last_key);
            cache.pop_back();
        }
        
        //insert
        cache.push_front({key,value});
        m[key]=cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
