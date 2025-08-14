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

vector<double> ropes;

int maxRopes(double x) {
    int res = 0;
    for(int i = 0; i < ropes.size(); i++) {
        res += floor(ropes[i]/x);
    }
    return res;
}

void solve() {
    int n, k; cin >> n >> k;

    ropes.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> ropes[i];
    }

    double maxRope = 0;
    for(int i = 0; i < n; i++) {
        maxRope = max(maxRope, ropes[i]);
    }

    double l = maxRope/k;
    double r = 1e8;
    for(int i = 0; i < 100; i++) {
        double mid = l+(r-l)/2;
        if(maxRopes(mid) >= k) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    cout << setprecision(10) << l << '\n';
}

int main() {
    solve();
}
