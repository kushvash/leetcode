class Solution {
public:
    unordered_map<int, vector<int>> m;
    unordered_set<int> visiting;
    unordered_set<int> done;
    vector<int> ans;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0; i<numCourses; i++){
            m[i]={};
        }

        for(auto& i: prerequisites){
            m[i[0]].push_back(i[1]);
        }

        for(int i=0; i<numCourses; i++){
            if(!dfs(i)){
                return {};
            }
        }

        return ans;
    }

    bool dfs(int crs){
        if(done.find(crs)!=done.end()){
            return true;
        }
        if(visiting.find(crs)!=visiting.end()){
            return false;
        }
        if(m[crs].size()==0){
            done.insert(crs);
            ans.push_back(crs);
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

        ans.push_back(crs);
        done.insert(crs);
        
        return true;
    }
};