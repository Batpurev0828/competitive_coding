#include <iostream>
#include <vector>
#include <set>
#include <queue>
#define ll long long
using namespace std;
 
vector<vector<pair<ll, ll>>> adj;
vector<ll> dist;
 
void dijkstra(ll s) {
    vector<bool> vis(dist.size(), false);	
    priority_queue<pair<ll, ll>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while (!pq.empty()) {
        ll u = pq.top().second;
        pq.pop();
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        for (auto x : adj[u]) {
            ll v = x.first;
            ll w = x.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
            }
        }
    }
}
 
void run() {
    ll n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    dist.resize(n + 1, 1e18);
    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    dijkstra(1);
    for (ll i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
}
 
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int32_t tc = 1;
    while (tc--) {
        run();
    }
    return 0;
}