#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct stack {
    vector<ll> v, cd;
    void push(ll x) {
        if (cd.empty()) cd.push_back(x);
        else cd.push_back(__gcd(cd.back(), x));
        v.push_back(x);
    }
    void pop() {
        v.pop_back();
        cd.pop_back();
    }
    ll top() {
        return v.back();
    }
    bool empty() {
        return cd.empty();
    }
} L, R;

void add(ll x) { R.push(x); }

void remove() {
    if (L.empty()) {
        while (!R.empty()) {
            ll x = R.top();
            L.push(x);
            R.pop();
        }
    }
    L.pop();
}

ll check() {
    if (L.empty()) return R.cd.back();
    if (R.empty()) return L.cd.back();
    return __gcd(L.cd.back(), R.cd.back());
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    ll n;
    cin >> n;
    vector<ll> nums(n);
    for (ll &i: nums) { cin >> i; }

    ll res = 1e18;

    for (ll r = 0, l = 0; r<n; ++r) {
        add(nums[r]);
        while (check() == 1) {
            res = min(res, r - l + 1);
            remove();
            ++l;
        }
    }

    cout << (res == 1e18 ? -1 : res) << '\n';

    return 0;
}