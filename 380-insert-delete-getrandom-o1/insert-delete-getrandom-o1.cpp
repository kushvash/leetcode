class RandomizedSet {
public:
    RandomizedSet() {
        
    }

    vector<int> directory;
    unordered_map<int, int> valToIndex;
    
    bool insert(int val) {
        if(valToIndex.find(val)!=valToIndex.end()) {
            return false;
        }

        valToIndex[val]=directory.size();
        directory.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(valToIndex.find(val)==valToIndex.end()) {
            return false;
        }

        int index=valToIndex[val];
        int newNum=directory.back();

        directory[index]=newNum;

        valToIndex[newNum]=index;
        valToIndex.erase(val);
        directory.pop_back();

        return true;
    }
    
    int getRandom() {
        int index=rand() % directory.size();
        return directory[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */