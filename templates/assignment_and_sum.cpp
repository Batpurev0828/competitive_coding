#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
// #include "debug_custom.h"
using namespace std;

vector<int> st, lazy;
vector<bool> has;

void push(int i, int L, int R) {
    if (!has[i] || L == R) return;
    [[maybe_unused]]int m = (L + R)/2;
    int x = 2 * i + 1, y = x + 1;
    has[x] = has[y] = true;
    st[x] = st[y] = lazy[i];
    lazy[x] = lazy[y] = lazy[i];
    lazy[i] = 0;
    has[i] = false;
}

int query(int i, int L, int R, int l, int r) {
    if (L == l && r == R) {
        return st[i];
    }
    push(i, L, R);
    int m = (L + R)/2;
    int x = 2 * i + 1, y = x + 1;
    if (r <= m) {
        return query(x, L, m, l, r);
    } else if (l > m) {
        return query(y, m + 1, R, l, r);
    } else {
        int q1 = query(x, L, m, l, m);
        int q2 = query(y, m + 1, R, m + 1, r);
        return min(q1, q2);
    }
}

void update(int i, int L, int R, int l, int r, int v) {
    if (L == l && r == R) {
        st[i] = v;
        lazy[i] = v;
        has[i] = true;
        return;
    }
    push(i, L, R);
    int m = (L + R)/2;
    int x = 2 * i + 1, y = x + 1;
    if (r <= m) {
        update(x, L, m, l, r, v);
    } else if (l > m) {
        update(y, m + 1, R, l, r, v);
    } else {
        update(x, L, m, l, m, v);
        update(y, m + 1, R, m + 1, r, v);
    }
    st[i] = min(st[x], st[y]);
}

int main() {
    // setIO("");
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    has.resize(4 * n, false);
    st.resize(4 * n, 0);
    lazy.resize(4 * n, 0);
    while (k--) {
        int q, l, r;
        cin >> q >> l >> r;
        if (q == 1) {
            int v;
            cin >> v;
            update(0, 0, n - 1, l, r - 1, v);
        } else {
            cout << query(0, 0, n - 1, l, r - 1) << '\n';
        }
    }
}