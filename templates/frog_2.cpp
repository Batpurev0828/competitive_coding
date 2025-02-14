#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<int> rocks(n), dp(n);
    for (int i = 0; i<n; ++i) {
        cin >> rocks[i];
        dp[i] = 1e9 + 7;
    }
    dp[0] = 0;
    for (int i = 0; i<n; ++i) {
        for (int j = 1; j<=k; ++j) {
            if (i + j < n) dp[i + j] = min(dp[i + j], dp[i] + abs(rocks[i] - rocks[i + j]));
        }
    }
    cout << dp[n - 1] << '\n';
}