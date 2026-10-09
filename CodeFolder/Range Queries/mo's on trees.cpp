// Use LCA

// Demo Code:
void solve(int tcase) {
    int n, q;
    cin >> n >> q;
    int timer = 0;
    vector<int> val(n+1), vals, Start(2*n+5), End(2*n+5), ID(2*n+5), vis(n+5);
    vector<int> cnt(100005), al(100005), pts(100005);
    vector<vector<int>> edges(n+1);
 
 
    for(int i=1; i<=n; i++) {
        cin >> val[i];
        vals.push_back(val[i]);
    }
 
    sort(all(vals));
    for(int i=1; i<=n; i++) {
        int c = lower_bound(all(vals), val[i]) - vals.begin();
        pts[c] = val[i];
        val[i] = c;
    }
 
    for(int i=1; i<n; i++) {
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
 
    function<void(int,int)> dfs = [&] (int u, int p) {
        Start[u] = ++timer; ID[timer] = u;
        for(auto v : edges[u]) {
            if(v != p) {
                dfs(v, u);
            }
        }
        End[u] = ++timer; ID[timer] = u;
    };
 
    dfs(1, -1);
    //println(stderr, "End: = {}", End);
 
    vector<pair<Query, int>> qs;
    LCA lca(edges);
 
    for(int i=1; i<=q; i++) { // <------ Important Setup Here
        int u, v, k, lc; cin >> u >> v >> k;
        lc = lca.lca(u, v);
        if(Start[u] > Start[v]) swap(u, v);
        int l, r;
        if(lc == u) l = Start[u], r = Start[v];
        else l = End[u], r = Start[v];
        if(l>r) swap(l,r);
        qs.push_back({Query{l, r, i, lc}, k});
    }
 
    vector<int> ans(q+1);
    sort(all(qs));
 
    auto toggle = [&] (int i) {
        if(vis[i]) {
            al[cnt[val[i]]] -= pts[val[i]];
            cnt[val[i]]--;
        } else {
            cnt[val[i]]++;
            al[cnt[val[i]]] += pts[val[i]];
        }
        vis[i] ^= 1;
    };
 
    int cur_l = 1, cur_r = 0;
    for(auto [q, k] : qs) {
        auto [l, r, id, lc] = q;
        //println(stderr, "L: {}, R: {}", l, r);
        while(cur_l>l) toggle(ID[--cur_l]);
        while(cur_r<r) toggle(ID[++cur_r]);
        while(cur_l<l) toggle(ID[cur_l++]);
        while(cur_r>r) toggle(ID[cur_r--]);
 
        // These are important in Mo's on Trees
        int u = ID[l], v = ID[r];
 
        if(lc!=u && lc!=v) toggle(lc);
        if(k<=n)ans[id] = al[k];
            else ans[id] = 0;
        if(lc!=u && lc!=v) toggle(lc);
    }
 
    for(int i=1; i<=q; i++) {
        cout << ans[i] << endl;
    }
}   