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

ll a, b, n;

bool fits(ll x) {
    if((x/a) * (x/b) >= n) return true;
    return false;
}

void solve() {
    cin >> a >> b >> n;

    ll l, r;
    for(ll k = 1; k < LONG_LONG_MAX; k*=2) {
        if(fits(k)) {
            r = k;
            break;
        }
        l = k;
    }
    while(l < r-1) {
        ll mid = l+(r-l)/2;
        if(fits(mid)) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    ans(r);
}

int main() {
    solve();
}
