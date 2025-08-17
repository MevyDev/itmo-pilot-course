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

int n, k;
vector<int> a;

bool works(ll x) {
    ll filled = 0;
    ll last = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] + last < x) {
            last += a[i];
        }
        else if(a[i] >= x) {
            filled++;
        }
        else {
            filled++;
            last = (a[i]+last)%x;
        }
        if(filled >= k) {
            return true;
        }
    }
    return false;
}

void solve() {
    cin >> k >> n;
    a.resize(n);
    for(auto &A : a) {
        cin >> A;
    }

    ll l = 0;
    ll r = (ll)*max_element(all(a)) * n;
    while(l+1 < r) {
        ll mid = l+(r-l)/2;
        if(works(mid)) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    ans(l);
}

int main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
