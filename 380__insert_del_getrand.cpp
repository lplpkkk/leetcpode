class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int,int> map;

public:
    RandomizedSet() {
        //do nothing    
    }
    
    bool insert(int val) {
        if (map.count(val)){
            return false;
        }

        map[val]=nums.size();
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(map.count(val)==0){
            return false;
        }

        int idx=map[val];
        int last_element=nums.back();

        nums[idx]=last_element;
        map[last_element]=idx;

        nums.pop_back();
        map.erase(val);

        return true;
    }
    
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
