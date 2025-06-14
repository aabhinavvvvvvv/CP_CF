#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

vector<pair<int, int>> adj[MAXN]; 
int dist[MAXN]; 

void insert_basis(vector<int>& basis, int x) {
    for (int &b : basis) {
        if ((x ^ b) < x) x ^= b;
    }
    if (x) basis.push_back(x);
    sort(basis.rbegin(), basis.rend());
}

int reduce_with_basis(const vector<int>& basis, int x) {
    for (int b : basis) {
        if ((x ^ b) < x) x ^= b;
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
    }

    fill(dist, dist + n + 1, -1);
    dist[1] = 0;

    queue<int> q;
    q.push(1);

    vector<int> basis;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto [v, w] : adj[u]) {
            int newXor = dist[u] ^ w;

            if (dist[v] == -1) {
                dist[v] = newXor;
                q.push(v);
            } else {
                int cycleXor = dist[v] ^ newXor;
                if (cycleXor != 0)
                    insert_basis(basis, cycleXor);
            }
        }
    }

    if (dist[n] == -1) {
        cout << -1 << '\n';
    } else {
        cout << reduce_with_basis(basis, dist[n]) << '\n';
    }

    return 0;
}
