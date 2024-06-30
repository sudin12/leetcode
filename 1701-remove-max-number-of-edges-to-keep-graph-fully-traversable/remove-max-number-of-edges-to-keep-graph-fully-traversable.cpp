class Solution {
    bool static comp(vector<int>& a, vector<int>& b) { return a[0] > b[0]; }
    int findparent(int node, vector<int>& parent) {
        if (node == parent[node])
            return node;
        return parent[node] = findparent(parent[node], parent);
    }
    bool unionn(int u, int v, vector<int>& parent, vector<int>& rank) {
        u = findparent(u, parent);
        v = findparent(v, parent);

        if (u != v) {
            if (rank[u] < rank[v])
                parent[u] = v;
            else if (rank[u] > rank[v])
                parent[v] = u;
            else {
                parent[v] = u;
                rank[u]++;
            }
            return true;
        }
        return false;
    }
public:
   
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int>parent_alice(n+1);
        vector<int>parent_bob(n+1);
        vector<int>alice_rank(n+1);
        vector<int>bob_rank(n+1);

        sort(edges.begin(),edges.end(),comp);

        for(int i=0;i<parent_alice.size();i++){
            parent_alice[i]=i;
            parent_bob[i]=i;
            alice_rank[i]=1;
            bob_rank[i]=1;
        }
        int remove_edges=0;
        int merge_alice=1;
        int merge_bob=1;
        for(auto it:edges){
            if(it[0]==3){
                bool temp_alice=unionn(it[1],it[2],parent_alice,alice_rank);
                bool temp_bob=unionn(it[1],it[2],parent_bob,bob_rank);

                if(temp_alice==true){
                    merge_alice++;
                }
                if(temp_bob==true){
                    merge_bob++;
                }
                if(temp_alice==false && temp_bob==false){
                    remove_edges++;
                }
            }else if(it[0]==1){
                bool temp_alice=unionn(it[1],it[2],parent_alice,alice_rank);
                if(temp_alice==true){
                    merge_alice++;
                }else{
                    remove_edges++;
                }
            }else{
                bool temp_bob=unionn(it[1],it[2],parent_bob,bob_rank);
                if(temp_bob==true){
                    merge_bob++;
                }
                else{
                    remove_edges++;
                }
            }

        }
        if(merge_alice!=n || merge_bob!=n) return -1;
        return remove_edges;
    }
};