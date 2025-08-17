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

int n;
vector<int> pos, speed;

bool works(double t) {
    vector<array<double, 2>> ranges(n);
    for(int i = 0; i < n; i++) {
        double rad = speed[i]*t;
        ranges[i][0] = pos[i] - rad;
        ranges[i][1] = pos[i] + rad;
    }
    double leastLeft = INT_MIN;
    double leastRight = INT_MAX;
    for(auto &range : ranges) {
        leastLeft = max(leastLeft, range[0]);
        leastRight = min(leastRight, range[1]);
    }
    return leastLeft <= leastRight;
}

void solve() {
    cin >> n;
    pos.resize(n);
    speed.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> pos[i] >> speed[i];
    }
    double l=0;
    double r=1e10;
    while(l+0.000001 < r) {
        double mid = l+(r-l)/2;
        if(works(mid)) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    cout << setprecision(15) << l << '\n';
}

int main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
