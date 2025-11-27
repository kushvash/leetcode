class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    unordered_map<int, int> recordMap;
    vector<int> recordArr;
    
    bool insert(int val) {
        if(recordMap.find(val)!=recordMap.end()) {
            return false;
        }

        recordArr.push_back(val);
        recordMap[val]=recordArr.size()-1;

        return true;
    }
    
    bool remove(int val) {
        if(recordMap.find(val)==recordMap.end()) {
            return false;
        }

        int index=recordMap[val], n=recordArr.size();
        int replaceVal=recordArr[n-1];

        recordArr[index]=replaceVal;
        recordMap[replaceVal]=index;

        recordMap.erase(val);
        recordArr.pop_back();

        return true;
    }
    
    int getRandom() {
        int n=recordArr.size();

        int index=rand()%n;

        return recordArr[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */