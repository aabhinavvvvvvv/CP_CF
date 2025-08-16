#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<long long> tree;
    SegTree(int n) : n(n), tree(4 * n + 5, 0) {}

    void build(vector<long long> &arr, int node, int l, int r) {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, node * 2, l, mid);
        build(arr, node * 2 + 1, mid + 1, r);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    void update(int node, int l, int r, int pos, long long val) {
        if (l == r) {
            tree[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(node * 2, l, mid, pos, val);
        else update(node * 2 + 1, mid + 1, r, pos, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    long long query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return query(node * 2, l, mid, ql, qr) +
               query(node * 2 + 1, mid + 1, r, ql, qr);
    }
};

int n, q, timer = 0;
vector<vector<int>> adj;
vector<int> tin, subsize;
vector<long long> val, flat;

void dfs(int u, int p) {
    tin[u] = ++timer;          // 1-indexed time
    flat[tin[u]] = val[u];
    subsize[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        subsize[u] += subsize[v];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    val.resize(n + 1);
    adj.assign(n + 1, {});
    tin.resize(n + 1);
    subsize.resize(n + 1);
    flat.resize(n + 1);

    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1);

    SegTree st(n);
    st.build(flat, 1, 1, n);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int s;
            long long x;
            cin >> s >> x;
            st.update(1, 1, n, tin[s], x);
        } else {
            int s;
            cin >> s;
            int l = tin[s];
            int r = tin[s] + subsize[s] - 1;
            cout << st.query(1, 1, n, l, r) << "\n";
        }
    }
}
