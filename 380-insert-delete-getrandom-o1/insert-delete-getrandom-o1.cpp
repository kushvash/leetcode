class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    unordered_map<int, int> record;
    // int i=0;
    vector<int> arr;

    bool insert(int val) {
        if(record.find(val)!=record.end()){
            return false;
        }
        record[val]=arr.size();
        arr.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(record.find(val)==record.end()){
            return false;
        }
        int i=arr.size();
        record[arr[i-1]]=record[val];
        swap(arr[record[val]], arr[i-1]);
        arr.pop_back();
        record.erase(val);
        return true;
    }
    
    int getRandom() {
        int i=arr.size();
        int randomIndex = rand() % i;

        return arr[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */