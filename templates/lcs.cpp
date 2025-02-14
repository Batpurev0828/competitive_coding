#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#define ll long long
using namespace std;

string solve(vector<vector<int>> &dp, string a, string b, int i, int j) {
    if (i == 0 || j == 0) return "";
    if (a[i - 1] == b[j - 1]) return solve(dp, a, b, i - 1, j - 1) + b[j - 1];
    if (dp[i - 1][j] > dp[i][j - 1]) return solve(dp, a, b, i - 1, j);
    return solve(dp, a, b, i, j - 1);
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1; 
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << solve(dp, a, b, n, m) << '\n';
} 