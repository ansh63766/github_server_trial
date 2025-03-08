#include <bits/stdc++.h>
using namespace std;

vector<int> get_path(int st, int en, const vector<vector<int>>& adj) {
    int n = adj.size() - 1;
    vector<int> parent(n + 1, -1);
    queue<int> q;
    q.push(st);
    parent[st] = st;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == en) break;
        for (int v : adj[u]) {
            if (parent[v] == -1) {
                parent[v] = u;
                q.push(v);
            }
        }
    }

    vector<int> path;
    int u = en;
    while (true) {
        path.push_back(u);
        if (u == st) break;
        u = parent[u];
        if (u == -1) return {}; // should not happen in a tree
    }
    reverse(path.begin(), path.end());
    return path;
}

void post_order(int u, int p, const vector<vector<int>>& adj, vector<bool>& in_path, vector<int>& res) {
    for (int v : adj[u]) {
        if (v == p || in_path[v]) continue;
        post_order(v, u, adj, in_path, res);
    }
    res.push_back(u);
}

void solve() {
    int n, st, en;
    cin >> n >> st >> en;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (st == en) {
        if (n == 1) {
            cout << "1 " << endl;
        } else {
            cout << -1 << endl;
        }
        return;
    }

    vector<int> path = get_path(st, en, adj);
    if (path.back() != en) {
        cout << -1 << endl;
        return;
    }

    vector<bool> in_path(n + 1, false);
    for (int u : path) {
        in_path[u] = true;
    }

    vector<int> permutation;

    permutation.push_back(st);
    permutation.push_back(en);

    // Post-order for path nodes (except en)
    for (int i = 0; i < (int)path.size() - 1; ++i) {
        int u = path[i];
        vector<int> children;
        for (int v : adj[u]) {
            if (!in_path[v] && v != path[i + 1] && (i == 0 || v != path[i - 1])) {
                children.push_back(v);
            }
        }
        for (int v : children) {
            vector<int> tmp;
            post_order(v, u, adj, in_path, tmp);
            for (int x : tmp) {
                permutation.push_back(x);
            }
        }
    }

    // Post-order for en's subtree (nodes not in path)
    vector<int> en_children;
    for (int v : adj[en]) {
        if (v != path[path.size() - 2]) {
            en_children.push_back(v);
        }
    }
    for (int v : en_children) {
        vector<int> tmp;
        post_order(v, en, adj, in_path, tmp);
        for (int x : tmp) {
            permutation.push_back(x);
        }
    }

    // Check if all nodes are included
    if (permutation.size() != n) {
        cout << -1 << endl;
        return;
    }

    for (int x : permutation) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}