#include <iostream>
#include <vector>
#include <stack>
#define ll long long
using namespace std;

ll n, k;
stack<ll> L, R;
stack<ll> lmin, lmax, rmin, rmax;

void add(ll x) {
    R.push(x);
    ll mx = rmax.empty() ? x : max(x, rmax.top());
    ll mn = rmin.empty() ? x : min(x, rmin.top());
    rmax.push(mx);
    rmin.push(mn);
}

void shift() {
    if (L.empty()) {
        while (!R.empty()) {
            ll x = R.top();
            R.pop();
            rmax.pop();
            rmin.pop();
            L.push(x);
            ll mx = lmax.empty() ? x : max(x, lmax.top());
            ll mn = lmin.empty() ? x : min(x, lmin.top());
            lmax.push(mx);
            lmin.push(mn);
        }
    }
}

void remove() {
    shift();
    if (!L.empty()) {
        L.pop();
        lmax.pop();
        lmin.pop();
    }
}

bool check() {
    if (lmax.empty()) return (rmax.top() - rmin.top() <= k);
    if (rmax.empty()) return (lmax.top() - lmin.top() <= k);
    ll mx = max(lmax.top(), rmax.top());
    ll mn = min(lmin.top(), rmin.top());
    return mx - mn <= k;
}

int main() {
    cin >> n >> k;
    vector<ll> nums(n);
    for (ll &i: nums) cin >> i;

    ll res = 0;
        
    for (ll r = 0, l = 0; r < n; ++r) {
        add(nums[r]);
        while (!check()) {
            remove();
            ++l;
        }
        res += r - l + 1;
    }

    cout << res << '\n';
}
