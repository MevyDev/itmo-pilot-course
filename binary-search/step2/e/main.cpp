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

bool isMoreThan(double x, double c) {
    return (x*x+sqrt(x)) >= c;
}

void solve() {
    double c; cin >> c;
    double l = 0;
    double r = sqrt(c);
    while(l + 0.000001 < r) {
        double m = l+(r-l)/2;
        if(isMoreThan(m, c)) {
            r = m;
        }
        else {
            l = m;
        }
    }
    cout << setprecision(10) << r;
}

int main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
