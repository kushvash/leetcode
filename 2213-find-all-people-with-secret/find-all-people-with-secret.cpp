class Solution {
    struct DSU {
        vector<int> p, r;
        DSU(int n): p(n), r(n,0) { iota(p.begin(), p.end(), 0); }
        int find(int x){ return p[x]==x? x : p[x]=find(p[x]); }
        void unite(int a,int b){
            a=find(a); b=find(b);
            if(a==b) return;
            if(r[a]<r[b]) swap(a,b);
            p[b]=a;
            if(r[a]==r[b]) r[a]++;
        }
        void reset(int x){ p[x]=x; r[x]=0; }
    };

public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(),
             [](const vector<int>& a, const vector<int>& b){ return a[2] < b[2]; });

        DSU dsu(n);
        dsu.unite(0, firstPerson);

        int m = (int)meetings.size();
        int i = 0;

        while (i < m) {
            int t = meetings[i][2];
            vector<int> people; // all participants at time t

            int j = i;
            while (j < m && meetings[j][2] == t) {
                int a = meetings[j][0], b = meetings[j][1];
                dsu.unite(a, b);
                people.push_back(a);
                people.push_back(b);
                ++j;
            }

            sort(people.begin(), people.end());
            people.erase(unique(people.begin(), people.end()), people.end());

            int root0 = dsu.find(0);
            for (int x : people) {
                if (dsu.find(x) != root0) {
                    dsu.reset(x); // break components that didn't connect to 0 at this time
                }
            }

            i = j;
        }

        vector<int> ans;
        int root0 = dsu.find(0);
        for (int x = 0; x < n; ++x) {
            if (dsu.find(x) == root0) ans.push_back(x);
        }
        return ans;
    }
};