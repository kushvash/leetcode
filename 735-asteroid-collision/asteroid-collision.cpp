class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;

        for(int asteroid: asteroids) {
            while(!stack.empty() && stack[stack.size()-1]>0 && asteroid<0) {
                int diff=stack[stack.size()-1]+asteroid;

                if(diff>0) {
                    asteroid=0;
                }else if(diff<0) {
                    stack.pop_back();
                }else {
                    asteroid=0;
                    stack.pop_back();
                }
            }

            if(asteroid!=0) {
                stack.push_back(asteroid);
            }
        }

        return stack;
    }
};