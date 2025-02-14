#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
#define ll long long
vector<ll> nums, st;

void build(ll i, ll L, ll R) {
    if (L == R) {
        st[i] = L;
        return;
    }
    ll m = (L + R)/2;
    ll x = i * 2 + 1, y = x + 1;
    build(x, L, m);
    build(y, m + 1, R);
    st[i] = (nums[st[x]] < nums[st[y]]) ? st[x] : st[y];
}

ll query(ll i, ll L, ll R, ll l, ll r) {
    if (L == l && r == R) {
        return st[i];
    }
    ll m = (L + R)/2;
    ll x = i * 2 + 1, y = x + 1;
    if (r <= m) return query(x, L, m, l, r);
    if (l > m) return query(y, m + 1, R, l, r);
    int q1 = query(x, L, m, l, m);
    int q2 = query(y, m + 1, R, m + 1, r);
    return (nums[q1] < nums[q2]) ? q1 : q2;
}

ll conquer(ll l, ll r) {
    ll n = nums.size();
    if (l > r) return 0;
    ll i = query(0, 0, n - 1, l, r);
    ll L = conquer(l, i - 1);
    ll R = conquer(i + 1, r);
    ll M = nums[i] * (r - l + 1);
    return max({L, R, M});
}

signed main() {

    ll n;
    cin >> n;
    nums.resize(n, 0);
    st.resize(n * 4, 0);
    for (ll &i: nums) cin >> i;
    build(0, 0, n - 1);
    cout << conquer(0, n - 1) << '\n';

    return 0;
}
