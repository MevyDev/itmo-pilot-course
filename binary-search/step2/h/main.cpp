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

string s;
ll ob=0, os=0, oc=0;
ll nb, ns, nc;
ll pb, ps, pc;
ll budget;

bool works(ll x) {
    ll bcost = max((ll)0, pb*(ob*x - nb));
    ll scost = max((ll)0, ps*(os*x - ns));
    ll ccost = max((ll)0, pc*(oc*x - nc));
    ll needed = bcost+scost+ccost;
    if(needed > budget) return false;
    return true;
}

void solve() {
    cin >> s >> nb >> ns >> nc >> pb >> ps >> pc >> budget;

    for(auto &A : s) {
            if(A == 'B') ob++;
            if(A == 'S') os++;
            if(A == 'C') oc++;
    }

    ll l = 0;
    ll r = 1e13;
    while(l+1 < r) {
        ll mid = l+(r-l)/2;
        if(works(mid)) {
            l=mid;
        }
        else {
            r=mid;
        }
    }
    ans(l);
}

int main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
