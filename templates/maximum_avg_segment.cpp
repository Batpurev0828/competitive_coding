#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <array>
#define ll long long
using namespace std;

vector<int> check(double m, int k, vector<double> &nums) {
    int n = nums.size();
    vector<double> pref(n + 1);
    vector<pair<double, int>> min_pref(n + 1);
    for (int i = 1; i<=n; ++i) {
        pref[i] = pref[i - 1] + nums[i - 1] - m;
    }
    min_pref[0] = {pref[0], 0};
    for (int i = 1; i<=n; ++i) {
        min_pref[i] = min(min_pref[i - 1], {pref[i], i});
    }
    for (int i = k; i<=n; ++i) {
        if (min_pref[i - k].first <= pref[i] + 1e-7){
            return {1, min_pref[i - k].second + 1, i};
        }
    }
    return {0};
}

void run() {
    int n, k;
    cin >> n >> k;
    vector<double> nums(n);
    bool ok = true;
    for (double &i : nums) {
        cin >> i;
        if (i != 0) {
            ok = false;
        }
    }
    if (ok) {
        cout << 1 << " " << k << "\n";
        return;
    }
    double l = 0, r = 1e9 + 7;
    vector<int> res;
    for (int i = 0; i < 100; ++i) {
        double m = (l + r) / 2;
        vector<int> query = check(m, k, nums);
        if (query[0]) {
            res = query;
            l = m;
        } else {
            r = m;
        }
    }
    if (res.empty()) {
        cout << -1 << "\n";
    } else {
        cout << res[1] << " " << res[2] << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    while (tc--) {
        run();
    }
    return 0;
}
