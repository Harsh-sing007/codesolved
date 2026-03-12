class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int find(int x){
        if(parent[x]!=x)
            parent[x]=find(parent[x]);
        return parent[x];
    }

    bool unite(int a,int b){
        a=find(a);
        b=find(b);

        if(a==b) return false;

        if(rank[a]<rank[b]) swap(a,b);

        parent[b]=a;
        if(rank[a]==rank[b]) rank[a]++;

        return true;
    }
};

class Solution {
public:
    
    bool can(int n, vector<vector<int>>& edges, int k, int x){

        DSU dsu(n);
        int used = 0;
        int upgrades = 0;

        vector<vector<int>> candidates;
        for(auto &e: edges){
            int u=e[0], v=e[1], s=e[2], must=e[3];

            if(must){
                if(s < x) return false;

                if(!dsu.unite(u,v)) return false;

                used++;
            }
        }
        for(auto &e: edges){
            int u=e[0], v=e[1], s=e[2], must=e[3];

            if(must) continue;

            if(s >= x)
                candidates.push_back({0,u,v});
            else if(2*s >= x)
                candidates.push_back({1,u,v});
        }

        sort(candidates.begin(), candidates.end());

        for(auto &c: candidates){
            int type=c[0], u=c[1], v=c[2];

            if(dsu.unite(u,v)){
                used++;
                upgrades += type;

                if(upgrades > k) return false;

                if(used == n-1) return true;
            }
        }

        return used == n-1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {

        int left = 1, right = 200000;
        int ans = -1;

        while(left <= right){
            int mid = (left + right)/2;

            if(can(n,edges,k,mid)){
                ans = mid;
                left = mid+1;
            }
            else
                right = mid-1;
        }

        return ans;
    }
};