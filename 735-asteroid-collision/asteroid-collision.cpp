class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;

        for(int asteroid: asteroids) {
            while(asteroid<0 && !res.empty() && res.back()>0) {
                if(-asteroid<res.back()) {
                    asteroid=0;
                }else if(-asteroid>res.back()) {
                    res.pop_back();
                }else {
                    res.pop_back();
                    asteroid=0;
                }
            }

            if(asteroid!=0) {
                res.push_back(asteroid);
            }
        }

        return res;
    }
};