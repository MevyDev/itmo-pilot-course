#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << #x << R"(: )" << x << endl;
#define ans(s) {cout << s << endl; return;}
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) x.begin(), x.end()
#define pb push_back
#define fi first
#define se second

int n, m, d;
vector<vector<array<int, 2>>> graph;

vector<int> path;

bool works(int x) {
    path.clear();
    path.resize(n, -1);
    path[0] = -2;
    queue<array<int, 3>> q;
    q.push({0, -1, 0});
    while(!q.empty()) {
        int curNode = q.front()[0];
        int lastNode = q.front()[1];
        int iter = q.front()[2];
        if(iter > d) return false;
        if(path[curNode] == -1) {
            path[curNode] = lastNode;
        }
        if(curNode == n-1) return true;
        q.pop();
        for(auto node : graph[curNode]) {
            if(node[1] > x) continue;
            q.push({node[0], curNode, iter+1});
        }
    }
    return false;
}

void solve() {
    cin >> n >> m >> d;
    graph.resize(m);
    for(int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--;
        b--;
        graph[a].pb({b, c});
    }

    int l = 0;
    int r = 2e9;
    while(l+1 < r) {
        int mid = l+(r-l)/2;
        if(works(mid)) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    if(!works(r)) {
        ans(-1);
    }
    vector<int> finalPath;
    int curPos = n-1;
    while(curPos != -2) {
        finalPath.pb(curPos);
        curPos = path[curPos];
    }
    reverse(all(finalPath));
    cout << size(finalPath)-1 << '\n';
    for(auto &NODE : finalPath) {
        cout << NODE+1 << ' ';
    }
    cout << '\n';
    return;
}

int main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
