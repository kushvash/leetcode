class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (groupSize <= 0) return false;
        if (n % groupSize != 0) return false;
        if (groupSize == 1) return true;

        // Count with unordered_map for O(1) average lookups
        unordered_map<int,int> cnt;
        // cnt.reserve(hand.size() * 2);
        for (int x : hand) cnt[x]++;

        // Sort unique card values once to process in ascending order
        vector<int> keys;
        keys.reserve(cnt.size());
        for (auto& kv : cnt) keys.push_back(kv.first);
        sort(keys.begin(), keys.end());

        // Greedy: start as many groups as the count at each key
        for (int start : keys) {
            int need = cnt[start];
            if (need == 0) continue;

            // Consume 'need' cards from start .. start+groupSize-1
            for (int v = start; v < start + groupSize; ++v) {
                auto it = cnt.find(v);
                if (it == cnt.end() || it->second < need) return false;
                it->second -= need;
            }
        }
        return true;
    }
};