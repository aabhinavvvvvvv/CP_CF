#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;
using state = tuple<int,int,int>;

#define fastIO() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define rep(i,a,b) for(int i=a; i<b; ++i)

void solve() {
    int n; cin >> n;
    vi curr(n), req(n);
    rep(i,0,n) cin >> curr[i];
    rep(i,0,n) cin >> req[i];

    // Step 1: Check impossible cases
    int maxB = *max_element(req.begin(), req.end());
    bool hasSource = false;
    rep(i,0,n) if(curr[i] == maxB) hasSource = true;
    rep(i,0,n) if(curr[i] > req[i]) {
        cout << "-1\n"; // Can't cool dishes
        return;
    }
    if(!hasSource) {
        cout << "-1\n"; // No dish can serve as source for maxB
        return;
    }

    // Step 2: Collect dishes by target temperatures
    map<int, vector<int>> targetPos;
    rep(i,0,n) targetPos[req[i]].push_back(i);

    vector<pii> ops; // store operations (i,j)

    // Step 3: Process targets descending (so we always have a source)
    vector<int> sortedTargets;
    for(auto &[t,v] : targetPos) sortedTargets.push_back(t);
    sort(sortedTargets.rbegin(), sortedTargets.rend()); // descending

    // Track source indices for each target
    map<int,int> sourceIdx;

    // Initialize source for max target
    for(int i=0;i<n;i++) if(curr[i] == maxB) {
        sourceIdx[maxB] = i;
        break;
    }


    for(int t : sortedTargets) {
        vector<int> &indices = targetPos[t];

        int src = -1;
        if(sourceIdx.count(t)) src = sourceIdx[t];
        else {
            // find any dish already at t
            for(int idx : indices) if(curr[idx] == t) { src = idx; break; }
            if(src == -1) {
                cout << "-1\n"; // impossible, no source
                return;
            }
            sourceIdx[t] = src;
        }

        for(int idx : indices) {
            if(curr[idx] == t) continue;
            ops.push_back({idx+1, src+1}); // 1-based index
            curr[idx] = t; // update
        }
    }

    // Step 4: Output operations
    cout << ops.size() << '\n';
    for(auto [i,j] : ops) cout << i << ' ' << j << '\n';
}

int main() {
    fastIO();
#ifdef LOCAL
    freopen("Error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t; cin >> t;
    rep(tc,1,t+1) {
        cout << "Case #" << tc << ": ";
        solve();
    }

    return 0;
}
