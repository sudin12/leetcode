class Solution {
public:
    static vector<vector<int>> getAncestors(const int n,
                                            const vector<vector<int>>& edges) {
        vector<int> deg(n, 0);
        vector<vector<int>> adj(n);

        for (auto& e : edges) { // Build adjacent list
            const int v = e[0], w = e[1];
            adj[v].push_back(w);
            deg[w]++; // indegree
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
            if (deg[i] == 0)
                q.push(i);

        vector<vector<int>> ancestor(n);

        while (!q.empty()) {
            const int v = q.front();
            q.pop();

            //bitset for v and all ancestors of v
            bitset<1000> S_v=0;
            for (const int x : ancestor[v])
                S_v[x] = 1;
            int m0 = v, mN = v;// min & max for v and all ancestors of v
            S_v[v]=1;
            if (ancestor[v].size()) {
                m0 = min(m0, ancestor[v][0]);
                mN = max(mN, ancestor[v].back());
            }
            for (const int w : adj[v]) {
                auto& aw = ancestor[w];
                // Add v and all ancestors of v to the ancestors[w]
                bitset<1000> S = S_v;
                
                for (int x : aw)
                    S[x] = 1;
                if (aw.size()) {
                    m0 = min(m0, aw[0]);
                    mN = max(mN, aw.back());
                }
                
                aw.resize(mN+1);
                int sz = 0;
                for (int x = m0; x <= mN; x++) {
                    if (S[x]) aw[sz++] = x;
                }
                aw.resize(sz);

                if (--deg[w] == 0)
                    q.push(w); // push vertex with 0 deg
            }
        }

        return ancestor;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();