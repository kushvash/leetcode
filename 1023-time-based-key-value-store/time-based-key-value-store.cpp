class TimeMap {
    

public:
    TimeMap() {
        
    }

    unordered_map<string, vector<pair<int, string>>> record;
    
    void set(string key, string value, int timestamp) {
        record[key].push_back({timestamp, value});
        return;    
    }
    
    string get(string key, int timestamp) {
        auto it = record.find(key);
        if (it == record.end() || it->second.empty()){
            return "";
        }

        auto &currV = it->second;

        int n = (int)currV.size();
        int lo = 0, hi = n - 1, mid;

        if (currV[0].first > timestamp){
            return "";
        }
        
        while(lo<hi){
            mid=lo+(hi-lo+1)/2;

            if(currV[mid].first>timestamp){
                hi=mid-1;
            }else{
                lo=mid;
            }
        }

        return currV[lo].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */