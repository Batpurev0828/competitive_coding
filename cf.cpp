#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
void floyd(int n, vector<vector<ll>>& dist) {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}
 
void solve() {
    ll n, m, q;
    cin >> n >> m >> q;
 
    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF));
 
    for (int i = 1; i <= n; ++i) {
        dist[i][i] = 0;
    }
 
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        dist[a][b] = min(dist[a][b], (ll)w);
        dist[b][a] = min(dist[b][a], (ll)w);
    }
 
    floyd(n, dist);
 
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
 
        if (dist[a][b] == INF) {
            cout << "-1\n";
        } else {
            cout << dist[a][b] << '\n';
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}