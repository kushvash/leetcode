class Solution {
public:
    unordered_map<int, vector<int>> m;
    unordered_set<int> visiting;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0; i<numCourses; i++){
            m[i]={};
        }

        for(auto& pairs: prerequisites){
            m[pairs[0]].push_back(pairs[1]);
        }

        for(int i=0; i<numCourses; i++){
            if(!dfs(i)){
                return false;
            }
        }

        return true;
    }

    bool dfs(int crs){
        if(visiting.find(crs)!=visiting.end()){
            return false;
        }
        if(m[crs].empty()){
            return true;
        }
        visiting.insert(crs);

        for(auto& i: m[crs]){
            if(!dfs(i)){
                return false;
            }
        }

        visiting.erase(crs);
        m[crs]={};
        return true;
    }
};