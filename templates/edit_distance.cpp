#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define ll long long
using namespace std;
const ll MOD = 1e9 + 7;
vector<vector<int>> dp;
void run() {
    string a, b;
    cin >> a >> b;
    dp.resize(a.size() + 1, vector<int>(b.size() + 1, -1));
    int n = a.length();
    int m = b.length();
    for (int i = 0; i<=n; ++i) 
        dp[i][0] = i;
    for (int i = 0; i<=m; ++i)
        dp[0][i] = i;
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min({
                    dp[i][j - 1],
                    dp[i - 1][j],
                    dp[i - 1][j - 1]
                });
            }
        }
    }
    cout << dp[n][m] << '\n';
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