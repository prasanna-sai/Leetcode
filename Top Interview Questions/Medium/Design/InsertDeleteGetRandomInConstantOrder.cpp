class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int, int> valToIndex;
    vector<int> value;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        
        if(valToIndex.find(val) != valToIndex.end())
            return false;
        
        int index = value.size();
        valToIndex[val] = index;
        value.push_back(val);
        
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        
        auto itr = valToIndex.find(val);
        if(itr == valToIndex.end())
            return false;
        
        int index = itr->second;
        int lastIdx = value.size() - 1;

        if (index != lastIdx) {
            value[index] = value.back();
            valToIndex[value.back()] = index;
        }

        value.pop_back();
        valToIndex.erase(itr);

        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return value[rand()%value.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */