class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        for(char& c: s) {
            freq[c]++;
        }

        priority_queue<pair<int, char>> maxHeap;
        
        string res;

        for(auto& [c, f]: freq) {
            maxHeap.push({f, c});
        }

        while(!maxHeap.empty()) {
            auto [tempF, tempC]=maxHeap.top();
            maxHeap.pop();

            res.append(tempF, tempC);
        }

        return res;   
    }
};