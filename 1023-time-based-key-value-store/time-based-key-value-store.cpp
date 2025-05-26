class TimeMap {
public:
    TimeMap() {
        
    }
    unordered_map<string, vector<pair<string, int>>> record;

    void set(string key, string value, int timestamp) {
        record[key].push_back({value, timestamp});    
        return;
    }
    
    pair<string, int> findBinary(vector<pair<string, int>>& curr, int& timestamp){
        int lo=0, hi=curr.size()-1, mid;

        if(curr[lo].second>timestamp){
            return {"", 0};
        }else if(curr[hi].second<timestamp){
            return curr[hi];
        }

        while(lo<hi){
            mid=lo+(hi-lo+1)/2;

            if(curr[mid].second>timestamp){
                hi=mid-1;
            }else{
                lo=mid;
            }
        }

        return curr[lo];
    }

    string get(string key, int timestamp) {
        if(record.find(key)==record.end()){
            return ""; 
        }

        pair<string, int> ans = findBinary(record[key], timestamp);

        return ans.first;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */