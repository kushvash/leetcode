class Solution {
public:
    bool isValid(string s) {
        stack<char> order;

        unordered_map<char, char> pairs={
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for(char c: s) {
            if(pairs.find(c)!=pairs.end()) {
                if(order.empty() || pairs[c]!=order.top()) {
                    return false;
                }
                order.pop();
            }else {
                order.push(c);
            }
        }

        return order.empty();
    }
};