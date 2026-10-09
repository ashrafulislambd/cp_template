int farthest(vector<vector<int>>& G, int s, vector<int>& d) {
	int n = G.size()+1;
	d.assign(n+1, n);
	d[s] = 0;
	vector<bool> vis(n+1);
	queue<int> q;
	q.push(s);
	vis[s] = true;
	d[s] = 0;
	int last = s;
 
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = true;
		for(auto& v : G[u]) {
			if(!vis[v]) {
				q.push(v);
				d[v] = d[u] + 1;
				last = v;
			}
		}
	}
 
	return last;
}