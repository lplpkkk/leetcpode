class AllOne {
    struct Node{
        int cnt;
        unordered_set<string> keys;
    };
    
    list<Node> nodes;
    unordered_map<string, list<Node>::iterator> cache;

public:
    AllOne() {
        //do nothing    
    }
    
    void inc(string key) {
        if(cache.find(key)==cache.end()){
           //this is a new one
           if(nodes.empty()||nodes.front().cnt>1){
                nodes.push_front({1,{key}});
           }else{
                nodes.front().keys.insert(key);
           }
           cache[key]=nodes.begin();
        }else{
            auto curr=cache[key];
            auto next_node=next(curr);
            
            // x->x
            // 4  5 |

            if(next_node==nodes.end()||next_node->cnt>curr->cnt+1){
                //create a new space
                next_node=nodes.insert(next_node,{curr->cnt+1,{}});
            }
            next_node->keys.insert(key);
            cache[key]=next_node;

            curr->keys.erase(key);
            if(curr->keys.empty()) nodes.erase(curr);
        }
    }
    
    void dec(string key) {
        auto curr=cache[key];// curr is the node that mapping the ky
        if(curr->cnt==1){
            cache.erase(key);
        }else{
            auto prev_node=prev(curr);
            if( curr==nodes.begin()||curr->cnt>prev_node->cnt+1){
                prev_node=nodes.insert(curr, {curr->cnt-1,{}});
            }
            prev_node->keys.insert(key);
            cache[key]=prev_node;
        }
        curr->keys.erase(key);
        if(curr->keys.empty()) nodes.erase(curr);
    }
    
    string getMaxKey() {
        return nodes.empty()?"": *nodes.back().keys.begin();
    }
    
    string getMinKey() {
        return nodes.empty()?"": *nodes.front().keys.begin();    
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
