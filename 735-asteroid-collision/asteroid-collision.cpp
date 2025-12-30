class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> res;

        for(int asteroid: asteroids) {
            while(!st.empty() && st.top()>0 && asteroid<0) {
                int diff=st.top()+asteroid;

                if(diff>0) {
                    asteroid=0;
                }else if(diff<0) {
                    st.pop();
                }else {
                    asteroid=0;
                    st.pop();
                }
            }

            if(asteroid!=0) {
                st.push(asteroid);
            }
        }

        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};